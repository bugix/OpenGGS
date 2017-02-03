#include "globals.h"

GameVariables_Type GV;
SavedOptions_Type SavedOptions;
World_Type World;
char Path_to_ini[300];

// ##############################################
// ##############################################
// ##############################################

void GAME_ENVIRONMENT_Define()
{
  STAGES_Files_Names_Load();
  World.Gravity = 1;
  World.Friction = 1;
  World.TerminalVelocity = 15;
  World.WallFriction = 7;
  World.TileSwitchSpeed = 50;

  Sprite_Bullet.ExplosionAnimation = 0;
  Sprite_Bullet.ExplosionX = 0;
  Sprite_Bullet.ExplosionY = 0;
  Sprite_Bullet.ExplosionDuraion = 100;

  GV.Screen_Width = 640;
  GV.Screen_Height = 480;
  GV.ScreenWidthTiles = (int)(GV.Screen_Width/16);
  GV.Resolution = RESOLUTION_640x480;
  GV.PixelPerfectRunning = true; // SO FAR THERE IS NO REASON EVER TO SWITCH THIS TO FALSE
  GV.RandomLevels = false;

  GV.ShowDebugInfos_Tiles = false;
  GV.SplashscreensEnabled = true;

  GV.VolumeSounds = 32;  // 0-128
  GV.VolumeMusic = 32;   // 0-128
  GV.TempMusicVolume = 0; // 0-128
  GV.TempMusicOffCounter = 0; // USED TO FADE OUT MUSIC DURING POWER UP
  GV.MusicEnabled = true;

  GV.DirAmigaExists = false;
  GV.DirDefaultExists = false;
  GV.DirC64Exists = false;

  TS.Tile_Width = 16;
  TS.Tile_Height = 16;

  TS.Width = TILESHEET_WIDTH_TILES;
  TS.Height = TILESHEET_HEIGHT_TILES;
  TS.Width_Pixels = TS.Width * TS.Tile_Width;
  TS.Height_Pixels = TS.Height * TS.Tile_Height;

  ME.Frame_3 = 0;
  ME.Frame_4 = 0;
  ME.Frame_6 = 0;
  ME.Frame_8 = 0;
  EV.Frame = 0;
  EV.Frame_4 = 0;
  EV.Frame_7 = 0;

  GV.GameType = TYPE_AMIGA;

  int x;
  for(x=0; x < NUMBER_OF_TILES; x++)
  {
    TS.Solid[x] = true;
    TS.Exit[x] = false;
    TS.Lethal[x] = false;
    TS.Fire[x] = false;
  }

  Joystick.UP = 0;
  Joystick.RIGHT = 3;
  Joystick.DOWN = 1;
  Joystick.LEFT = 2;
  Joystick.Jump = 10;   //BUTTON A
  Joystick.OK = 10;     //BUTTON A
  Joystick.Shoot = 11;
  Joystick.ESCAPE = 5; // XBOX-BUTTON

    //  4 = START
    //  5 = SELECT
    //  8 = LB
    //  9 = RB
    // 11 = B
    // 12 = X
    // 13 = Y
    // 14 = XBOX-BUTTON

  //Options_Load();
  //Options_Save();
}

// ##############################################
// ##############################################
// ##############################################

void Options_Save()
{
  SavedOptions.Screen_Width = GV.Screen_Width;
  SavedOptions.Screen_Height = GV.Screen_Height;
  SavedOptions.VolumeMusic = VolumePercentage_Music;
  SavedOptions.VolumeSounds = VolumePercentage_Sound;
  SavedOptions.GameType = GV.GameType;

  FILE *Options_File;
  Options_File = fopen ("base/Options.oi", "wb");

  if (Options_File != NULL)
  {
    fwrite (&SavedOptions, sizeof (SavedOptions), 1, Options_File);    // write data
    fclose (Options_File);    // close file again
  }
}
// ##############################################
// ##############################################
// ##############################################

void Options_Load()
{
  FILE *Options_File;
  Options_File = fopen ("base/Options.oi", "rb");

  if (Options_File != NULL)
  {
    fread (&SavedOptions, sizeof (SavedOptions), 1, Options_File);
    GV.Screen_Width = SavedOptions.Screen_Width;
    GV.Screen_Height = SavedOptions.Screen_Height;
    if(GV.Screen_Width == 640 && GV.Screen_Height == 480){GV.Resolution = RESOLUTION_640x480;}
    if(GV.Screen_Width == 800 && GV.Screen_Height == 600){GV.Resolution = RESOLUTION_800x600;}
    if(GV.Screen_Width == 1280 && GV.Screen_Height == 720){GV.Resolution = RESOLUTION_1280x720;}
    VolumePercentage_Sound = SavedOptions.VolumeSounds;
    VolumePercentage_Music = SavedOptions.VolumeMusic;

    AUDIO_Volume_Change_Music(VolumePercentage_Music, false);
    AUDIO_Volume_Change_Sound(VolumePercentage_Sound, false);
    fclose (Options_File);
  }
}

// ##############################################
// ##############################################
// ##############################################

void Option_GameType_Load()
{
  FILE *Options_File;
  Options_File = fopen ("base/Options.oi", "rb");

  if (Options_File != NULL)
  {
    fread (&SavedOptions, sizeof (SavedOptions), 1, Options_File);
    GV.GameType = SavedOptions.GameType;
    fclose (Options_File);
  }
  //GAMETYPE_Load();
}

// ##############################################
// ##############################################
// ##############################################
