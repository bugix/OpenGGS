#include "globals.h"
Uint32 timecounter;
Uint32 timecounter_Animation;
Uint32 timecounter_Animation_Tiles_Fast;
Uint32 timecounter_TileSwitch;

HUD_Def HUD;

// ##############################################
// ##############################################
// ##############################################

void LOOP_Gameloop_Standard()
{
  int GameModeTemp = GV.Mode;
  GV.Mode = MODE_GAMELOOP;

  TS.NextFrame = false;
  timecounter=SDL_GetTicks();
  timecounter_Animation=SDL_GetTicks();
  timecounter_Animation_Tiles_Fast=SDL_GetTicks();
  timecounter_TileSwitch=SDL_GetTicks();


  if(CurrentScreenMode == 1){SDL_ShowCursor(0);}

  if(StageC64.BackgroundColour == 0){AUDIO_Music_Play(MUSIC_OUTDOORS);}
  if(StageC64.BackgroundColour == 1){AUDIO_Music_Play(MUSIC_INDOORS);}


  while(!QuitProgram && !QuitToMenu)
  {
    Unified.Jump = false;

    getInput();
    INPUT_General();

    if(Key_UP || Joy_JUMP){Unified.Jump = true;}

    if(Key_ESCAPE_pressed || Joy_ESCAPE_pressed){QuitToMenu = true;}
    //if(Key_F1_pressed) {PC.ShowBorder = !PC.ShowBorder;}
    if(Key_F2_pressed) {STAGE_Load(PC.Stage, 0, true, false);}
    if(Key_F3_pressed)
    {
      PC.Stage++;  if(PC.Stage > 37){PC.Stage = 0;}
      STAGE_Load(PC.Stage, 0, true, false);
    }
    if(Key_F4_pressed)
    {
      PC.Stage--; if(PC.Stage < 0){PC.Stage = 37;}
      STAGE_Load(PC.Stage, 0, true, false);
    }
    //if(Key_F5_pressed) {GV.ShowDebugInfos_Tiles = !GV.ShowDebugInfos_Tiles;}
    if(Key_F7_pressed) {PC_PowerUp_Set(PC.PowerUp+1);}
    if(Key_F8_pressed) {PC_PowerUp_Set(PC.PowerUp-1);}

    if(Key_F9_pressed) {GV.PixelPerfectRunning = !GV.PixelPerfectRunning;}

    if(Key_TAB_pressed) {}

    if(Key_CTRL_pressed || Joy_SHOOT) {SPRITE_Bullet_Activate();}

    if(PC.Exit_Reached)
    {
      if(PC.Stage == 33){PC.Stage = 1; STAGE_Load(PC.Stage, 0, false, false); QuitToMenu = true;}  // LAST STAGE
      else if(PC.Stage > 33){PC.Stage = PC.SubStageEntryStage; STAGE_Load(PC.Stage, 3, false, false);} // EXITING A SUBSTAGE
      else if(PC.Stage < 33){PC.Stage++; STAGE_Load(PC.Stage, 0, true, true);}                   // NORMAL STAGE
    }

    if(PC.WarpCounter == 1) {LOOP_Gameloop_Warpscreen();}

    // TURN MUSIC BACK ON AFTER POWERUP-FADEOUT
    if(GV.TempMusicOffCounter == 1 && GV.TempMusicVolume !=0)
    {
      GV.VolumeMusic = GV.TempMusicVolume;
      Mix_VolumeMusic(GV.VolumeMusic);
      GV.TempMusicVolume = 0;
    }

    if(!PC.Dead && PC.WarpCounter == 0)
    {
      if(Key_UP_pressed || Joy_JUMP_pressed)    {PC.JumpOnGoing = true;}
      if(Key_LEFT || Joy_LEFT)          {PC.AccellLeft = true;}
      if(Key_RIGHT || Joy_RIGHT)         {PC.AccellRight = true;}
      if(!Key_LEFT && !Joy_LEFT)         {PC.AccellLeft = false;}
      if(!Key_RIGHT && !Joy_RIGHT)        {PC.AccellRight = false;}
      if(Key_LEFT_pressed || Key_RIGHT_pressed || Joy_LEFT_pressed || Joy_RIGHT_pressed){PC_Run();}
    }

    if(SDL_GetTicks() - timecounter_Animation > 150)
    {
      timecounter_Animation = SDL_GetTicks();
      PC.Animation++;
      if(PC.Animation>2){PC.Animation = 1;}
    }

    if(SDL_GetTicks() - timecounter > 20)
    {
      timecounter = SDL_GetTicks();
      if(PC.gotKilled){PC_Killed();}

      if(PC.JumpOnGoing || PC.Dead){PC_Jump();}
      if(!Key_LEFT_pressed && !Key_RIGHT_pressed && !PC.Dead && PC.WarpCounter == 0){PC_Run();}

      if(PC.WarpCounter == 0){PC_Gravity();}
      PC_Friction();
      ENEMIES_Move();
      SPRITES_Move();

      if(!PC.Dead && PC.PosY > -1)
      {
        PC_Check_Tilecollision();
        PC_Check_TilecollisionNonSolid();
        PC_Check_Collision_Sprites();
      }

      if(PC.GotoSubStage)
      {
        PC.GotoSubStage = false;
        PC.SubStageEntryStage = PC.Stage;
        PC.Stage = 34+PC.SubStageNumber;
        PC.SubStageNumber++;
        if(PC.SubStageNumber>3){PC.SubStageNumber=0;}
        STAGE_Load(PC.Stage, 0, false, false);
      }

      if(PC.Dead){PC_Death_Routine();}

      if(PC.JumpOnGoing){PC.Stance = PC_JUMP;}
      if(!PC.JumpOnGoing && !PC.AccellRight && !PC.AccellLeft){PC.Stance = PC_STAND;}
      if(!PC.JumpOnGoing && (PC.AccellRight || PC.AccellLeft))
      {
        if(PC.Animation==1){PC.Stance = PC_WALK1;}
        if(PC.Animation==2){PC.Stance = PC_WALK2;}
      }
      if(!PC.OnGround && PC.PosY < GV.Screen_Height){PC.Stance = PC_JUMP;}  // E.G. WALKING OFF A CLIFF
      if(PC.AccellLeft && PC.RunVelocity > 0) {PC.Stance = PC_TURN;}
      if(PC.AccellRight && PC.RunVelocity < 0){PC.Stance = PC_TURN;}

      if(PC.Lives < 1 && !PC.Dead){PC_Define(); STAGE_Load(PC.Stage, 0, false, false); QuitToMenu = true;} // LOST ALL LIVES. RESET PC AND GO TO MENU
    }
    Update_Screen();  // draw the scene
  }
  GV.Mode = GameModeTemp;
  SDL_ShowCursor(1);
  getInput();  // make sure no "pressed key" is carried over to the menu...
}

// ##############################################
// ##############################################
// ##############################################
