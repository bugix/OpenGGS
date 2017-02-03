#include "globals.h"

StageDef_C64 StageC64;
StageCacheDef_C64 StageCache_C64;
BackGroundElements_Def BackGroundElements;

ImportStage_Struct ImportStage;

// ##############################################
// ##############################################
// ##############################################

void STAGE_Save(int StageNumber)
{
  STAGE_Copy_To_Cache(StageNumber);

  int x, y;
  FILE *Stage_File;
  ImportStage_Struct ExportStage; // all the data of one stage (currently approx 35KB per stage!)
  Stage_File = fopen (FileName.Stage[0], "rb+");
  // open file in binary mode

  // COPY StageCache_C64 TO Export.Stage
  for(y = 0; y < 30; y++)
  {
    for (x = 0; x < 256; x++)
    {
      ExportStage.Array[x][y] = StageCache_C64.TileNumber[StageNumber][x][y];

      ExportStage.StartPositionX[0] = StageCache_C64.StartPositionX[StageNumber][0];
      ExportStage.StartPositionY[0] = StageCache_C64.StartPositionY[StageNumber][0];
      ExportStage.StartPositionX[1] = StageCache_C64.StartPositionX[StageNumber][1];
      ExportStage.StartPositionY[1] = StageCache_C64.StartPositionY[StageNumber][1];
      ExportStage.StartPositionX[2] = StageCache_C64.StartPositionX[StageNumber][2];
      ExportStage.StartPositionY[2] = StageCache_C64.StartPositionY[StageNumber][2];
      ExportStage.StartPositionX[3] = StageCache_C64.StartPositionX[StageNumber][3];
      ExportStage.StartPositionY[3] = StageCache_C64.StartPositionY[StageNumber][3];
    }
  }
  ExportStage.BackgroundColour = StageCache_C64.BackgroundColour[StageNumber];
  ExportStage.TileType = StageCache_C64.TileType[StageNumber]; // above ground, underground, different colours...
  ExportStage.WarpToStage = StageCache_C64.WarpToStage[StageNumber];
  ExportStage.PlatformInUse = StageCache_C64.PlatformInUse[StageNumber];
  ExportStage.PlatformX = StageCache_C64.PlatformX[StageNumber];
  ExportStage.PlatformY = StageCache_C64.PlatformY[StageNumber];
  ExportStage.PlatformType = StageCache_C64.PlatformType[StageNumber];
  ExportStage.PlatformDirection = StageCache_C64.PlatformDirection[StageNumber];
  ExportStage.PlatformPathLength = StageCache_C64.PlatformPathLength[StageNumber];
  ExportStage.PlatformMovePos = StageCache_C64.PlatformMovePos[StageNumber];
  ExportStage.Substage_StartPositionX = StageCache_C64.Substage_StartPositionX[StageNumber];
  ExportStage.Substage_StartPositionY = StageCache_C64.Substage_StartPositionY[StageNumber];
  ExportStage.Substage_PlatformInUse = StageCache_C64.Substage_PlatformInUse[StageNumber];
  ExportStage.Substage_PlatformX = StageCache_C64.Substage_PlatformX[StageNumber];
  ExportStage.Substage_PlatformY = StageCache_C64.Substage_PlatformY[StageNumber];
  ExportStage.Substage_PlatformType = StageCache_C64.Substage_PlatformType[StageNumber];
  ExportStage.Substage_PlatformDirection = StageCache_C64.Substage_PlatformDirection[StageNumber];
  ExportStage.Substage_PlatformPathlength = StageCache_C64.Substage_PlatformPathlength[StageNumber];
  ExportStage.Substage_PlatformMovePos = StageCache_C64.Substage_PlatformMovePos[StageNumber];
  for(y = 0; y < 40; y++)
  {
    for (x = 0; x < 30; x++)
    {
      ExportStage.Substage_Array[x][y] = StageCache_C64.Substage_Array[StageNumber][x][y];
    }
  }

  for (x = 0; x < MAX_NUM_ENEMIES; x++)
  {
    ExportStage.Enemy_Type[x] = StageCache_C64.Enemy_Type[StageNumber][x];
    ExportStage.Enemy_InUse[x] = StageCache_C64.Enemy_InUse[StageNumber][x];
    ExportStage.Enemy_Direction[x] = StageCache_C64.Enemy_Direction[StageNumber][x];
    ExportStage.Enemy_PosX[x] = StageCache_C64.Enemy_PosX[StageNumber][x]*TS.Tile_Width;
    ExportStage.Enemy_PosY[x] = StageCache_C64.Enemy_PosY[StageNumber][x]*TS.Tile_Height;
  }


  for (x = 0; x < 100; x++)
  {
    ExportStage.Name[x] = StageCache_C64.Name[StageNumber][x];
  }
  // COPY StageCache_C64 TO Export.Stage

  if (Stage_File != NULL)
  {
    fseek(Stage_File, StageNumber * sizeof (ExportStage), SEEK_SET); // MOVE TO StageNumber
    fwrite (&ExportStage, sizeof (ExportStage), 1, Stage_File);    // WRITE DATA
    fclose (Stage_File);
  }
}

// ##############################################
// ##############################################
// ##############################################

void STAGES_Import()
{
  int x, y;
  int StageNumber = 0;

  FILE *Stages_File;
  Stages_File = fopen (FileName.Stage[0], "rb");

  if (Stages_File != NULL)
  {
    // move to data set in question...
    for(StageNumber = 0; StageNumber < 38; StageNumber++)
    {
      fseek(Stages_File, StageNumber * sizeof (ImportStage), SEEK_SET);
      fread (&ImportStage, sizeof (ImportStage), 1, Stages_File); // read data

     // load tile array
      for(y = 0; y < 30; y++)
      {
        for (x = 0; x < 256; x++)
        {
          StageCache_C64.TileNumber[StageNumber][x][y] = ImportStage.Array[x][y];
          StageCache_C64.StartPositionX[StageNumber][0] = ImportStage.StartPositionX[0];
          StageCache_C64.StartPositionY[StageNumber][0] = ImportStage.StartPositionY[0];
          StageCache_C64.StartPositionX[StageNumber][1] = ImportStage.StartPositionX[1];
          StageCache_C64.StartPositionY[StageNumber][1] = ImportStage.StartPositionY[1];
          StageCache_C64.StartPositionX[StageNumber][2] = ImportStage.StartPositionX[2];
          StageCache_C64.StartPositionY[StageNumber][2] = ImportStage.StartPositionY[2];
          StageCache_C64.StartPositionX[StageNumber][3] = ImportStage.StartPositionX[3];
          StageCache_C64.StartPositionY[StageNumber][3] = ImportStage.StartPositionY[3];
        }
      }
      StageCache_C64.BackgroundColour[StageNumber] = ImportStage.BackgroundColour;
      StageCache_C64.TileType[StageNumber] = ImportStage.TileType; // above ground, underground, different colours...

      StageCache_C64.WarpToStage[StageNumber] = ImportStage.WarpToStage;
      StageCache_C64.PlatformInUse[StageNumber] = ImportStage.PlatformInUse;
      StageCache_C64.PlatformX[StageNumber] = ImportStage.PlatformX;
      StageCache_C64.PlatformY[StageNumber] = ImportStage.PlatformY;
      StageCache_C64.PlatformType[StageNumber] = ImportStage.PlatformType;
      StageCache_C64.PlatformDirection[StageNumber] = ImportStage.PlatformDirection;
      StageCache_C64.PlatformPathLength[StageNumber] = ImportStage.PlatformPathLength;
      StageCache_C64.PlatformMovePos[StageNumber] = ImportStage.PlatformMovePos;
      StageCache_C64.Substage_StartPositionX[StageNumber] = ImportStage.Substage_StartPositionX;
      StageCache_C64.Substage_StartPositionY[StageNumber] = ImportStage.Substage_StartPositionY;

      StageCache_C64.Substage_PlatformInUse[StageNumber] = ImportStage.Substage_PlatformInUse;
      StageCache_C64.Substage_PlatformX[StageNumber] = ImportStage.Substage_PlatformX;
      StageCache_C64.Substage_PlatformY[StageNumber] = ImportStage.Substage_PlatformY;
      StageCache_C64.Substage_PlatformType[StageNumber] = ImportStage.Substage_PlatformType;
      StageCache_C64.Substage_PlatformDirection[StageNumber] = ImportStage.Substage_PlatformDirection;
      StageCache_C64.Substage_PlatformPathlength[StageNumber] = ImportStage.Substage_PlatformPathlength;
      StageCache_C64.Substage_PlatformMovePos[StageNumber] = ImportStage.Substage_PlatformMovePos;

      for(y = 0; y < 40; y++)
      {
        for (x = 0; x < 30; x++)
        {
          StageCache_C64.Substage_Array[StageNumber][x][y] = ImportStage.Substage_Array[x][y];
        }
      }

      for (x = 0; x < MAX_NUM_ENEMIES; x++)
      {
        StageCache_C64.Enemy_Type[StageNumber][x] = ImportStage.Enemy_Type[x];
        StageCache_C64.Enemy_InUse[StageNumber][x] = ImportStage.Enemy_InUse[x];
        StageCache_C64.Enemy_Direction[StageNumber][x] = ImportStage.Enemy_Direction[x];
        StageCache_C64.Enemy_PosX[StageNumber][x] = (int)(ImportStage.Enemy_PosX[x]/TS.Tile_Width);
        StageCache_C64.Enemy_PosY[StageNumber][x] = (int)(ImportStage.Enemy_PosY[x]/TS.Tile_Height);
      }

      for (x = 0; x < 100; x++)
      {
        StageCache_C64.Name[StageNumber][x] = ImportStage.Name[x];
      }

      // IF RANDOMIZED LEVELS, CREATE A RANDOM LEVEL SET
      if(GV.RandomLevels)
      {
        LOOP_Editor_Stages_Create(StageCache_C64.BackgroundColour[StageNumber], true, true, false);
        STAGE_Copy_To_Cache(StageNumber);
      }
      // IF RANDOMIZED LEVELS, CREATE A RANDOM LEVEL SET
    }
    fclose (Stages_File);
   }

  // LOAD FIRST STAGE
  STAGE_Load(1, 0, false, false);

  // LOAD FIRST STAGE INTO EDITOR CACHE
  LOOP_Editor_Stages_Load_Stage(1);
}

// ##############################################
// ##############################################
// ##############################################

void STAGE_Copy_To_Cache(int StageNumber)
{
  // COPY EVERYTHING TO StageCache_C64 AND StageC64
  int x,y;
  for(y = 0; y < 30; y++)
  {
    for (x = 0; x < 256; x++)
    {
      StageCache_C64.TileNumber[StageNumber][x][y] = ME.TileNumber[x][y];
    }
  }
  for (x = 0; x < 4; x++)
  {
    StageCache_C64.StartPositionX[StageNumber][x] = ME.StartPositionX_Tile[x]*TS.Tile_Width;
    StageCache_C64.StartPositionY[StageNumber][x] = ME.StartPositionY_Tile[x]*TS.Tile_Height;
  }

  for (x = 0; x < MAX_NUM_ENEMIES; x++)
  {
    StageCache_C64.Enemy_PosX[StageNumber][x] = ME.Enemy_PosX[x];  // EDITOR HAS ENEMY POSITION ON TILES NOT PIXELS
    StageCache_C64.Enemy_PosY[StageNumber][x] = ME.Enemy_PosY[x]; // EDITOR HAS ENEMY POSITION ON TILES NOT PIXELS
    StageCache_C64.Enemy_InUse[StageNumber][x] = ME.Enemy_InUse[x];
    StageCache_C64.Enemy_Direction[StageNumber][x] = ME.Enemy_Direction[x];
    StageCache_C64.Enemy_Type[StageNumber][x] = ME.Enemy_Type[x];
  }

  StageCache_C64.TileType[StageNumber] = ME.TileType;

  StageCache_C64.PlatformInUse[StageNumber] = ME.Platform_inUse;
  StageCache_C64.PlatformX[StageNumber] = ME.Platform_Start_X;
  StageCache_C64.PlatformY[StageNumber] = ME.Platform_Start_Y;
  StageCache_C64.PlatformPathLength[StageNumber] = ME.Platform_Start_Y-ME.Platform_End_Y;
  StageCache_C64.BackgroundColour[StageNumber] = ME.BackgroundColour;

  STAGE_Copy_To_StageC64();

}

// ##############################################
// ##############################################
// ##############################################

void STAGE_Load(int StageNumber, int CheckPointNumber, bool ShowSplashScreen, bool ShowResultspage)
{
  int x,y;
  int LastColWithTile = 0;

  // RESET EVERYTHING
  PC.RunVelocity = 0;
  PC.JumpVelocity = 0;
  PC.Direction = PC_RIGHT;
  PC.JumpOnGoing = false;
  PC.AccellLeft = false;
  PC.AccellRight = false;
  PC.ShowBorder = false;
  PC.Dead = false;
  PC.gotKilled = false;
  PC.WallGrinding = false;
  PC.JumpStrength = 24;
  PC.Exit_Reached = false;
  Sprite_Bullet.Active = false;
  for(x=1; x<10; x++) {Sprite_PowerUp[x].Active = false;}
  for(x=1; x<20; x++) {Sprite_SmallCoin[x].Active = false;}
  for(x=1; x<30; x++)
  {
    Sprite_DropStone[x].PosX = 0;
    Sprite_DropStone[x].PosY = 0;
    Sprite_DropStone[x].inUse = false;
    Sprite_DropStone[x].JumpVelocity = 0;
  }
  // RESET EVERYTHING

  for(y=0; y<30; y++)
  {
    for(x=0; x<256; x++)
    {
      StageC64.TileNumber[x][y] = 0;
    }
  }

  for(y=0; y<30; y++)
  {
    for(x=0; x<256; x++)
    {
      StageC64.TileNumber[x][y] = 0;
      if(y==29){StageC64.TileNumber[x][y] = 41;}
      if(y==26){StageC64.TileNumber[x][y] = 41;}
      if(x==255){StageC64.TileNumber[x][y] = 41;}
      if(x==1){StageC64.TileNumber[x][y] = 41;}
    }
  }

  for(y = 0; y < 30; y++)
  {
    for (x = 0; x < 256; x++)
    {
      StageC64.TileNumber[x][y] = StageCache_C64.TileNumber[StageNumber][x][y];
      if(StageC64.TileNumber[x][y] != 0){LastColWithTile = x;}
      StageC64.AnimationCounter[x][y] = 0;
    }
  }

  // MATCH STAGEWIDTH TO LAST TILE ON STAGE
  StageC64.StageHeight = 30;
  StageC64.StageWidth = LastColWithTile+1;
  StageC64.StageHeightPixels = StageC64.StageHeight * TS.Tile_Height;
  StageC64.StageWidthPixels = StageC64.StageWidth * TS.Tile_Width;
  // MAKE SURE STAGE IS AT LEAST AS WIDE AS SCREEN
  while(StageC64.StageWidthPixels < GV.Screen_Width){StageC64.StageWidthPixels++;}

  for(x = 0; x < 4; x++)
  {
    StageC64.CheckPointX[x] = StageCache_C64.StartPositionX[StageNumber][x];
    StageC64.CheckPointY[x] = StageCache_C64.StartPositionY[StageNumber][x];
  }

  for (x = 0; x < MAX_NUM_ENEMIES; x++)
  {
    Enemy[x].Type = StageCache_C64.Enemy_Type[StageNumber][x];
    Enemy[x].inUse = StageCache_C64.Enemy_InUse[StageNumber][x];
    Enemy[x].Direction = StageCache_C64.Enemy_Direction[StageNumber][x];
    Enemy[x].PosX = StageCache_C64.Enemy_PosX[StageNumber][x]*TS.Tile_Width;
    Enemy[x].PosY = StageCache_C64.Enemy_PosY[StageNumber][x]*TS.Tile_Height;
    Enemy[x].StartPosX = Enemy[x].PosX;
    Enemy[x].StartPosY = Enemy[x].PosY;
    Enemy[x].Alive = true;
    Enemy[x].OnGround = false;
    Enemy[x].RunVelocity = 0;
    Enemy[x].JumpVelocity = 0;
    Enemy[x].Active = false;
    Enemy[x].MovementCounter = 0;
  }

  for(x=0;x<12;x++)
  {
    BackGroundElements.CloudPosX[x] = rand() % 3072;
    BackGroundElements.CloudPosY[x] = 32 + rand() % 118;
  }

  for(x=0;x<12;x++)
  {
    BackGroundElements.BrickPosX[x] = rand() % 3072;
    BackGroundElements.BrickPosY[x] = rand() % 320;
  }


  for(x=0;x<4;x++)
  {
    BackGroundElements.TubePosX[x] = (x*500) + rand() % 400; // DISTRIBUTE THE TUBE OVER THE MAP
    BackGroundElements.TubeFire[x] = rand() % 2;
  }

  PC.PosX = StageCache_C64.StartPositionX[StageNumber][CheckPointNumber];
  PC.PosY = StageCache_C64.StartPositionY[StageNumber][CheckPointNumber]+TS.Tile_Height;
  StageC64.BackgroundColour = StageCache_C64.BackgroundColour[StageNumber];
  StageC64.TileType = StageCache_C64.TileType[StageNumber];

  Platform.inUse = StageCache_C64.PlatformInUse[StageNumber];
  Platform.Start_X = StageCache_C64.PlatformX[StageNumber]*TS.Tile_Width;
  Platform.Start_Y = StageCache_C64.PlatformY[StageNumber]*TS.Tile_Height;
  Platform.End_X = Platform.Start_X;
  Platform.End_Y = Platform.Start_Y - (StageCache_C64.PlatformPathLength[StageNumber]*TS.Tile_Height);
  Platform.PosX = Platform.Start_X;
  Platform.PosY = Platform.Start_Y;

  if(ShowSplashScreen && GV.SplashscreensEnabled){LOOP_Gameloop_Splashscreen();}

  if(GV.Mode == MODE_GAMELOOP && StageC64.BackgroundColour == 0){AUDIO_Music_Play(MUSIC_OUTDOORS);}
  if(GV.Mode == MODE_GAMELOOP && StageC64.BackgroundColour == 1){AUDIO_Music_Play(MUSIC_INDOORS);}
  if(GV.Mode == MODE_MENU){AUDIO_Music_Play(MUSIC_MENU);}
}

// ##############################################
// ##############################################
// ##############################################

void STAGE_Copy_To_StageC64()
{
  int x, y;
  // IF CURRENTLY PLAYED STAGE = CURRENTLY EDITED STAGE -> UPDATE IT AS WELL
  if(ME.Stage == PC.Stage)
  {
    for(y = 0; y < 30; y++)
    {
      for (x = 0; x < 256; x++)
      {
        StageC64.TileNumber[x][y] = ME.TileNumber[x][y];
        StageC64.TileType = ME.TileType;
      }
    }
    for (x = 0; x < MAX_NUM_ENEMIES; x++)
    {
      Enemy[x].PosX = ME.Enemy_PosX[x]*TS.Tile_Width;  // EDITOR HAS ENEMY POSITION ON TILES NOT PIXELS
      Enemy[x].PosY = ME.Enemy_PosY[x]*TS.Tile_Height; // EDITOR HAS ENEMY POSITION ON TILES NOT PIXELS
      Enemy[x].inUse = ME.Enemy_InUse[x];
      Enemy[x].Direction = ME.Enemy_Direction[x];
      Enemy[x].Type = ME.Enemy_Type[x];
    }

    Platform.inUse = ME.Platform_inUse;
    Platform.Start_X = ME.Platform_Start_X*TS.Tile_Width;
    Platform.Start_Y = ME.Platform_Start_Y*TS.Tile_Height;
    Platform.End_X = ME.Platform_End_X*TS.Tile_Width;
    Platform.End_Y = ME.Platform_End_Y*TS.Tile_Height;
    Platform.PosX = Platform.Start_X;
    Platform.PosY = Platform.Start_Y;
    StageC64.BackgroundColour = ME.BackgroundColour;
  }
}

// ##############################################
// ##############################################
// ##############################################

void STAGES_Files_Names_Load()
{
  DIR *dir;
  struct dirent *ent;
  int x;
  for(x=0; x<20; x++)
  {
    snprintf(FileName.Stage[x], sizeof(char) * 128, "---");
  }

  x = 1;
  if ((dir = opendir ("base/stages/")) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL)
    {
      if(strncmp("..", ent->d_name, 2) != 0 && strncmp(".", ent->d_name, 2) != 0)
      {
        snprintf(FileName.Stage[x], sizeof(char) * 128, "base/stages/%s",ent->d_name);
        snprintf(FileName.StageShort[x], sizeof(char) * 128, ent->d_name);
        x++;
        if(x>19){x=19;}
      }
    }
    closedir (dir);
  }
}

// ##############################################
// ##############################################
// ##############################################

void STAGES_Import_RANDOM_Modules()
{
  int x, y, z, a;
  int StageNumber = 0;

  FILE *Stages_File;
  Stages_File = fopen ("base/stages/modules.lvl", "rb");

  if (Stages_File != NULL)
  {
    // move to data set in question...
    for(StageNumber = 0; StageNumber < 38; StageNumber++)
    {
      fseek(Stages_File, StageNumber * sizeof (ImportStage), SEEK_SET);
      fread (&ImportStage, sizeof (ImportStage), 1, Stages_File); // read data

     // load tile array
      for(y = 0; y < 30; y++)
      {
        for (x = 0; x < 256; x++)
        {
          StageCache_C64.TileNumber[StageNumber][x][y] = ImportStage.Array[x][y];
        }
      }

      StageCache_C64.BackgroundColour[StageNumber] = ImportStage.BackgroundColour;

      for (x = 0; x < MAX_NUM_ENEMIES; x++)
      {
        StageCache_C64.Enemy_Type[StageNumber][x] = ImportStage.Enemy_Type[x];
        StageCache_C64.Enemy_InUse[StageNumber][x] = ImportStage.Enemy_InUse[x];
        StageCache_C64.Enemy_Direction[StageNumber][x] = ImportStage.Enemy_Direction[x];
        StageCache_C64.Enemy_PosX[StageNumber][x] = (int)(ImportStage.Enemy_PosX[x]/TS.Tile_Width);
        StageCache_C64.Enemy_PosY[StageNumber][x] = (int)(ImportStage.Enemy_PosY[x]/TS.Tile_Height);
      }

      // CLEAR ALL MODULES
      for(y = 0; y < 30; y++)
      {
        for (x = 0; x < 32; x++)
        {
          for (z = 0; z < 128; z++)
          {
            Stage_Random_Module_Outdoors[z].TileNumber[x][y] = 0;
            Stage_Random_Module_Indoors[z].TileNumber[x][y] = 0;
          }
          for (z = 0; z < 8; z++)
          {
            Stage_Random_Module_Outdoors_Exit[z].TileNumber[x][y] = 0;
            Stage_Random_Module_Indoors_Exit[z].TileNumber[x][y] = 0;
          }
        }
      }

      // CLEAR ALL MODULES
      for (z = 0; z < NUM_MODULES_OUTDOORS; z++)  // 16 MODULES
      {
        for(x = 0; x < MAX_NUM_ENEMIES_MODULE; x++)  // MAXIMUM ENEMIES PER MODULE
        {
          Stage_Random_Module_Outdoors[z].Enemy_InUse[x] = 0;
          Stage_Random_Module_Outdoors[z].Enemy_PosX[x] = 0;
          Stage_Random_Module_Outdoors[z].Enemy_PosY[x] = 0;
          Stage_Random_Module_Outdoors[z].Enemy_Direction[x] = 0;
          Stage_Random_Module_Outdoors[z].Enemy_Type[x] = 0;
        }
      }

      // CLEAR ALL MODULES
      for (z = 0; z < NUM_MODULES_INDOORS; z++)  // 16 MODULES
      {
        for(x = 0; x < MAX_NUM_ENEMIES_MODULE; x++)  // MAXIMUM ENEMIES PER MODULE
        {
          Stage_Random_Module_Indoors[z].Enemy_InUse[x] = 0;
          Stage_Random_Module_Indoors[z].Enemy_PosX[x] = 0;
          Stage_Random_Module_Indoors[z].Enemy_PosY[x] = 0;
          Stage_Random_Module_Indoors[z].Enemy_Direction[x] = 0;
          Stage_Random_Module_Indoors[z].Enemy_Type[x] = 0;
        }
      }

      // CLEAR ALL MODULES
      for (z = 0; z < NUM_MODULES_OUTDOORS_EXITS; z++)  // 16 MODULES
      {
        for(x = 0; x < MAX_NUM_ENEMIES_MODULE; x++)  // MAXIMUM ENEMIES PER MODULE
        {
          Stage_Random_Module_Outdoors_Exit[z].Enemy_InUse[x] = 0;
          Stage_Random_Module_Outdoors_Exit[z].Enemy_PosX[x] = 0;
          Stage_Random_Module_Outdoors_Exit[z].Enemy_PosY[x] = 0;
          Stage_Random_Module_Outdoors_Exit[z].Enemy_Direction[x] = 0;
          Stage_Random_Module_Outdoors_Exit[z].Enemy_Type[x] = 0;
        }
      }

      // CLEAR ALL MODULES
      for (z = 0; z < NUM_MODULES_INDOORS_EXITS; z++)  // 16 MODULES
      {
        for(x = 0; x < MAX_NUM_ENEMIES_MODULE; x++)  // MAXIMUM ENEMIES PER MODULE
        {
          Stage_Random_Module_Indoors_Exit[z].Enemy_InUse[x] = 0;
          Stage_Random_Module_Indoors_Exit[z].Enemy_PosX[x] = 0;
          Stage_Random_Module_Indoors_Exit[z].Enemy_PosY[x] = 0;
          Stage_Random_Module_Indoors_Exit[z].Enemy_Direction[x] = 0;
          Stage_Random_Module_Indoors_Exit[z].Enemy_Type[x] = 0;
        }
      }



      // LOADING ENEMIES INTO OUTDOOR-MODULES
      int ModuleCounter = 0;
      int ModuleInStage = 0;
      int EnemyInModuleCounter = 0;
      int EnemySlot = 0;
      bool SlotFound = false;
      for (a = 0; a < 16; a++)  // 16 STAGES
      {
        for (z = 0; z < MAX_NUM_ENEMIES; z++)  // CYCLE THROUGH ALL ENEMIES WITHIN A STAGE
        {
          if(StageCache_C64.Enemy_InUse[a+1][z] == 1) //+1, BECAUSE IT STARTS AT STAGE 1
           {

            ModuleInStage = StageCache_C64.Enemy_PosX[a+1][z]/32; // THE NUMBER OF THE MODULE WITHIN THE STAGE (0-7)
            ModuleCounter = ModuleInStage+(a*8); // NUMBER OF THE MODULE
            SlotFound = false;
            EnemyInModuleCounter = 0;
            while(!SlotFound && EnemyInModuleCounter < 5)
            {
              if(Stage_Random_Module_Outdoors[ModuleCounter].Enemy_InUse[EnemyInModuleCounter] == 0)
              {
                EnemySlot = EnemyInModuleCounter;
                Stage_Random_Module_Outdoors[ModuleCounter].Enemy_InUse[EnemySlot] = StageCache_C64.Enemy_InUse[a+1][z];
                Stage_Random_Module_Outdoors[ModuleCounter].Enemy_PosX[EnemySlot] = StageCache_C64.Enemy_PosX[a+1][z]-(ModuleInStage*32);
                Stage_Random_Module_Outdoors[ModuleCounter].Enemy_PosY[EnemySlot] = StageCache_C64.Enemy_PosY[a+1][z];
                Stage_Random_Module_Outdoors[ModuleCounter].Enemy_Direction[EnemySlot] = StageCache_C64.Enemy_Direction[a+1][z];
                Stage_Random_Module_Outdoors[ModuleCounter].Enemy_Type[EnemySlot] = StageCache_C64.Enemy_Type[a+1][z];
                SlotFound = true;
              }
              EnemyInModuleCounter++;
            }
          }
        }
      }

      // LOADING ENEMIES INTO INDOOR-MODULES
      ModuleCounter = 0;
      ModuleInStage = 0;
      EnemyInModuleCounter = 0;
      EnemySlot = 0;
      SlotFound = false;
      for (a = 0; a < 16; a++)  // 16 STAGES
      {
        for (z = 0; z < MAX_NUM_ENEMIES; z++)  // CYCLE THROUGH ALL ENEMIES WITHIN A STAGE
        {
          if(StageCache_C64.Enemy_InUse[a+17][z] == 1) //+17, BECAUSE IT STARTS AT STAGE 17
           {
            ModuleInStage = StageCache_C64.Enemy_PosX[a+17][z]/32; // THE NUMBER OF THE MODULE WITHIN THE STAGE (0-7)
            ModuleCounter = ModuleInStage+(a*8); // NUMBER OF THE MODULE
            SlotFound = false;
            EnemyInModuleCounter = 0;
            while(!SlotFound && EnemyInModuleCounter < 5)
            {
              if(Stage_Random_Module_Indoors[ModuleCounter].Enemy_InUse[EnemyInModuleCounter] == 0)
              {
                EnemySlot = EnemyInModuleCounter;
                Stage_Random_Module_Indoors[ModuleCounter].Enemy_InUse[EnemySlot] = StageCache_C64.Enemy_InUse[a+17][z];
                Stage_Random_Module_Indoors[ModuleCounter].Enemy_PosX[EnemySlot] = StageCache_C64.Enemy_PosX[a+17][z]-(ModuleInStage*32);
                Stage_Random_Module_Indoors[ModuleCounter].Enemy_PosY[EnemySlot] = StageCache_C64.Enemy_PosY[a+17][z];
                Stage_Random_Module_Indoors[ModuleCounter].Enemy_Direction[EnemySlot] = StageCache_C64.Enemy_Direction[a+17][z];
                Stage_Random_Module_Indoors[ModuleCounter].Enemy_Type[EnemySlot] = StageCache_C64.Enemy_Type[a+17][z];
                SlotFound = true;
              }
              EnemyInModuleCounter++;
            }
          }
        }
      }

      // LOADING ENEMIES INTO OUTDOOR-EXIT-MODULES
      ModuleCounter = 0;
      ModuleInStage = 0;
      EnemyInModuleCounter = 0;
      EnemySlot = 0;
      SlotFound = false;
      a=0;  // 1 STAGES
      for (z = 0; z < MAX_NUM_ENEMIES; z++)  // CYCLE THROUGH ALL ENEMIES WITHIN A STAGE
      {
        if(StageCache_C64.Enemy_InUse[a+34][z] == 1) //+34, BECAUSE IT STARTS AT STAGE 34
         {
          ModuleInStage = StageCache_C64.Enemy_PosX[a+34][z]/32; // THE NUMBER OF THE MODULE WITHIN THE STAGE (0-7)
          ModuleCounter = ModuleInStage+(a*8); // NUMBER OF THE MODULE
          SlotFound = false;
          EnemyInModuleCounter = 0;
          while(!SlotFound && EnemyInModuleCounter < 5)
          {
            if(Stage_Random_Module_Outdoors_Exit[ModuleCounter].Enemy_InUse[EnemyInModuleCounter] == 0)
            {
              EnemySlot = EnemyInModuleCounter;
              Stage_Random_Module_Outdoors_Exit[ModuleCounter].Enemy_InUse[EnemySlot] = StageCache_C64.Enemy_InUse[a+34][z];
              Stage_Random_Module_Outdoors_Exit[ModuleCounter].Enemy_PosX[EnemySlot] = StageCache_C64.Enemy_PosX[a+34][z]-(ModuleInStage*32);
              Stage_Random_Module_Outdoors_Exit[ModuleCounter].Enemy_PosY[EnemySlot] = StageCache_C64.Enemy_PosY[a+34][z];
              Stage_Random_Module_Outdoors_Exit[ModuleCounter].Enemy_Direction[EnemySlot] = StageCache_C64.Enemy_Direction[a+34][z];
              Stage_Random_Module_Outdoors_Exit[ModuleCounter].Enemy_Type[EnemySlot] = StageCache_C64.Enemy_Type[a+34][z];
              SlotFound = true;
            }
            EnemyInModuleCounter++;
          }
        }
      }

      // LOADING ENEMIES INTO INDOOR-EXIT-MODULES
      ModuleCounter = 0;
      ModuleInStage = 0;
      EnemyInModuleCounter = 0;
      EnemySlot = 0;
      SlotFound = false;
      a=0;  // 1 STAGES
      for (z = 0; z < MAX_NUM_ENEMIES; z++)  // CYCLE THROUGH ALL ENEMIES WITHIN A STAGE
      {
        if(StageCache_C64.Enemy_InUse[a+35][z] == 1) //+35, BECAUSE IT STARTS AT STAGE 35
         {
          ModuleInStage = StageCache_C64.Enemy_PosX[a+35][z]/32; // THE NUMBER OF THE MODULE WITHIN THE STAGE (0-7)
          ModuleCounter = ModuleInStage+(a*8); // NUMBER OF THE MODULE
          SlotFound = false;
          EnemyInModuleCounter = 0;
          while(!SlotFound && EnemyInModuleCounter < 5)
          {
            if(Stage_Random_Module_Indoors_Exit[ModuleCounter].Enemy_InUse[EnemyInModuleCounter] == 0)
            {
              EnemySlot = EnemyInModuleCounter;
              Stage_Random_Module_Indoors_Exit[ModuleCounter].Enemy_InUse[EnemySlot] = StageCache_C64.Enemy_InUse[a+35][z];
              Stage_Random_Module_Indoors_Exit[ModuleCounter].Enemy_PosX[EnemySlot] = StageCache_C64.Enemy_PosX[a+35][z]-(ModuleInStage*32);
              Stage_Random_Module_Indoors_Exit[ModuleCounter].Enemy_PosY[EnemySlot] = StageCache_C64.Enemy_PosY[a+35][z];
              Stage_Random_Module_Indoors_Exit[ModuleCounter].Enemy_Direction[EnemySlot] = StageCache_C64.Enemy_Direction[a+35][z];
              Stage_Random_Module_Indoors_Exit[ModuleCounter].Enemy_Type[EnemySlot] = StageCache_C64.Enemy_Type[a+35][z];
              SlotFound = true;
            }
            EnemyInModuleCounter++;
          }
        }
      }

      // OUTDOOR-MODULES
      for(y = 0; y < 30; y++)  // 30 TILES HIGH
      {
        for (x = 0; x < 32; x++)  // 32 TILES WIDE
        {
          for (z = 0; z < 8; z++)  // 8 MODULES PER STAGE
          {
            for (a = 0; a < 16; a++)  // 16 STAGES
            {
              Stage_Random_Module_Outdoors[z+(8*a)].TileNumber[x][y] = StageCache_C64.TileNumber[a+1][x+(z*32)][y];
            }
          }
        }
      }

      // OUTDOOR-EXITS-MODULES
      for(y = 0; y < 30; y++)  // 30 TILES HIGH
      {
        for (x = 0; x < 32; x++)  // 32 TILES WIDE
        {
          for (z = 0; z < 8; z++)  // 8 MODULES PER STAGE
          {
              Stage_Random_Module_Outdoors_Exit[z].TileNumber[x][y] = StageCache_C64.TileNumber[34][x+(z*32)][y];
          }
        }
      }

      // INDOOR-MODULES
      for(y = 0; y < 30; y++)  // 30 TILES HIGH
      {
        for (x = 0; x < 32; x++)  // 32 TILES WIDE
        {
          for (z = 0; z < 8; z++)  // 8 MODULES PER STAGE
          {
            for (a = 0; a < 16; a++)  // 16 STAGES
            {
              Stage_Random_Module_Indoors[z+(8*a)].TileNumber[x][y] = StageCache_C64.TileNumber[a+17][x+(z*32)][y];
            }
          }
        }
      }

      // INDOOR-EXITS-MODULES
      for(y = 0; y < 30; y++)  // 30 TILES HIGH
      {
        for (x = 0; x < 32; x++)  // 32 TILES WIDE
        {
          for (z = 0; z < 8; z++)  // 8 MODULES PER STAGE
          {
            Stage_Random_Module_Indoors_Exit[z].TileNumber[x][y] = StageCache_C64.TileNumber[35][x+(z*32)][y];
          }
        }
      }

    }
    fclose (Stages_File);
  }


  // CHECK FILE

  FILE *f = fopen("test.txt", "w");

  fprintf(f, "OUTDOORS\n");
  for (z = 0; z < NUM_MODULES_OUTDOORS; z++)  // 16 MODULES
  {
    for(x = 0; x < MAX_NUM_ENEMIES_MODULE; x++)  // MAXIMUM ENEMIES PER MODULE
    {
      fprintf(f, "%d/%d - ", z, x);
      fprintf(f, "InUse: %d, ", Stage_Random_Module_Outdoors[z].Enemy_InUse[x]);
      fprintf(f, "X: %d, ", Stage_Random_Module_Outdoors[z].Enemy_PosX[x]);
      fprintf(f, "Y: %d, ", Stage_Random_Module_Outdoors[z].Enemy_PosY[x]);
      fprintf(f, "Dir: %d, ", Stage_Random_Module_Outdoors[z].Enemy_Direction[x]);
      fprintf(f, "Type: %d", Stage_Random_Module_Outdoors[z].Enemy_Type[x]);
      fprintf(f, "\n");
    }
  }

  fprintf(f, "-----\n");
  fprintf(f, "OUTDOORS-EXITS\n");
  for (z = 0; z < NUM_MODULES_OUTDOORS_EXITS; z++)  // 8 MODULES
  {
    for(x = 0; x < MAX_NUM_ENEMIES_MODULE; x++)  // MAXIMUM ENEMIES PER MODULE
    {
      fprintf(f, "%d/%d - ", z, x);
      fprintf(f, "InUse: %d, ", Stage_Random_Module_Outdoors_Exit[z].Enemy_InUse[x]);
      fprintf(f, "X: %d, ", Stage_Random_Module_Outdoors_Exit[z].Enemy_PosX[x]);
      fprintf(f, "Y: %d, ", Stage_Random_Module_Outdoors_Exit[z].Enemy_PosY[x]);
      fprintf(f, "Dir: %d, ", Stage_Random_Module_Outdoors_Exit[z].Enemy_Direction[x]);
      fprintf(f, "Type: %d", Stage_Random_Module_Outdoors_Exit[z].Enemy_Type[x]);
      fprintf(f, "\n");
    }
  }

  fprintf(f, "-----\n");
  fprintf(f, "INDOORS\n");
  for (z = 0; z < NUM_MODULES_INDOORS; z++)  // 16 MODULES
  {
    for(x = 0; x < MAX_NUM_ENEMIES_MODULE; x++)  // MAXIMUM ENEMIES PER MODULE
    {
      fprintf(f, "%d/%d - ", z, x);
      fprintf(f, "InUse: %d, ", Stage_Random_Module_Indoors[z].Enemy_InUse[x]);
      fprintf(f, "X: %d, ", Stage_Random_Module_Indoors[z].Enemy_PosX[x]);
      fprintf(f, "Y: %d, ", Stage_Random_Module_Indoors[z].Enemy_PosY[x]);
      fprintf(f, "Dir: %d, ", Stage_Random_Module_Indoors[z].Enemy_Direction[x]);
      fprintf(f, "Type: %d", Stage_Random_Module_Indoors[z].Enemy_Type[x]);
      fprintf(f, "\n");
    }
  }

  fprintf(f, "-----\n");
  fprintf(f, "INDOORS-EXITS\n");
  for (z = 0; z < NUM_MODULES_INDOORS_EXITS; z++)  // 8 MODULES
  {
    for(x = 0; x < MAX_NUM_ENEMIES_MODULE; x++)  // MAXIMUM ENEMIES PER MODULE
    {
      fprintf(f, "%d/%d - ", z, y);
      fprintf(f, "InUse: %d, ", Stage_Random_Module_Indoors_Exit[z].Enemy_InUse[x]);
      fprintf(f, "X: %d, ", Stage_Random_Module_Indoors_Exit[z].Enemy_PosX[x]);
      fprintf(f, "Y: %d, ", Stage_Random_Module_Indoors_Exit[z].Enemy_PosY[x]);
      fprintf(f, "Dir: %d, ", Stage_Random_Module_Indoors_Exit[z].Enemy_Direction[x]);
      fprintf(f, "Type: %d", Stage_Random_Module_Indoors_Exit[z].Enemy_Type[x]);
      fprintf(f, "\n");
    }
  }
  fclose(f);


}

// ##############################################
// ##############################################
// ##############################################
