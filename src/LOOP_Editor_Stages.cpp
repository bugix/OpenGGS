#include "globals.h"

Uint32 timecounter_StageEditor;
StagesEditor_Type ME;
bool Move_Right;
bool Move_Left;
Uint16 ScrollSpeed;

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages()
{
  int GameModeTemp = GV.Mode;
  GV.Mode = MODE_EDITOR_STAGES;
  Mix_HaltMusic();

  timecounter_StageEditor=SDL_GetTicks();

  ME.ShowInterface = false;
  ME.CurrentTileType = 501;
  ME.SingleTileMode = false;
  ME.DrawGrid = false;
  ME.CurrentStartPosition = -1;
  ME.CurrentEnemy = -1;
  ME.DontSetATile = false;
  ME.SquareThisBlock = false;
  ME.ElementGroup = 1;
  ME.CurrentEnemyType = 0;
  ME.Platform_StartGrabbed = false;
  ME.Platform_EndGrabbed = false;

  // LOAD STAGES FRESHLY - CACHE COULD BE CHANGED FROM RANDOM STAGE GENERATION
  //STAGES_Import();

  // MAKE SURE IT'S WINDOWED AND 4:3
  //if(GV.Resolution == RESOLUTION_1280x720){SYSTEM_SetResolution(RESOLUTION_640x480);}
  //if(CurrentScreenMode==1){toggleScreenmode();}

  int Stage_End = StageC64.StageWidthPixels-GV.Screen_Width-1; // UNCLEAR WHY "-1" IS NEEDED

  while(!QuitProgram && !QuitToMenu)
  {
    getInput();
    INPUT_General();

    Move_Left = false;
    Move_Right = false;

    if(Key_ESCAPE_pressed){QuitToMenu = true;}

    if(Key_F1_pressed) {ME.ShowInterface = !ME.ShowInterface;}
    if(Key_F2_pressed) {ME.DrawGrid = !ME.DrawGrid;}
    if(Key_F3_pressed) {ME.Stage++; if(ME.Stage > 37){ME.Stage = 0;} LOOP_Editor_Stages_Load_Stage(ME.Stage);}
    if(Key_F4_pressed) {ME.Stage--; if(ME.Stage < 0){ME.Stage = 37;} LOOP_Editor_Stages_Load_Stage(ME.Stage);}

    if(Key_F5_pressed) {}

    //if(Key_F6_pressed){ME.CurrentEnemyType = 0;}
    if(Key_F7_pressed) {ME.SquareThisBlock = !ME.SquareThisBlock;}

    if(Key_CTRL && Key_S_pressed) {STAGE_Save(ME.Stage); AUDIO_Sound_Play(AUDIO_DISK);}
    if(Key_F11_pressed){ME.SingleTileMode = !ME.SingleTileMode;}

    ScrollSpeed = 25;
    if(Key_CTRL){ScrollSpeed = 5;}

    if(Key_F8_pressed)
    {

    }


    if(Key_TAB_pressed) {ME.ElementGroup++; if(ME.ElementGroup>3){ME.ElementGroup = 1;}}

    if(Key_LALT && Key_ENTER_pressed)  {toggleScreenmode();}
    if(Key_LEFT)                       {Move_Left = true;}
    if(Key_RIGHT)                      {Move_Right = true;}
    if(Key_UP)                         {ME.StagePosX = 0;}
    if(Key_DOWN)                       {ME.StagePosX = Stage_End;}

    // SET A TILE
    if(MouseButtonLeft_pressed && !ME.ShowInterface && ME.CurrentEnemyType == 0)
    {
      int CheckX = (int)((MouseX+ME.StagePosX)/TS.Tile_Width);
      int CheckY = (int)((MouseY+ME.StagePosY)/TS.Tile_Height);
      LOOP_Editor_Stages_Set_Tile_Check(ME.CurrentTileType, CheckX, CheckY);
      if(!ME.DontSetATile)
      {
        LOOP_Editor_Stages_Set_Tile(ME.CurrentTileType, CheckX, CheckY);
      }
    }

    // DESELECT ENEMY IF BROWSING TILES
    if(ME.ShowInterface && ME.ElementGroup != 3){ME.CurrentEnemyType = 0;}

    // PICK A TILETYPE
    if(MouseButtonLeft_pressed && ME.ShowInterface)
    {
      LOOP_Editor_Stages_Pick_TileType();
      LOOP_Editor_Stages_Change_Stage_Settings();
    }

    // SET A NEW ENEMY
    if(MouseButtonLeft_pressed && !ME.ShowInterface && ME.CurrentEnemyType > 0)
    {
      int SetNewEnemyX = (int)((MouseX+ME.StagePosX)/TS.Tile_Width);
      int SetNewEnemyY = (int)((MouseY+ME.StagePosY)/TS.Tile_Height)+1;
      LOOP_Editor_Stages_Set_New_Enemy(ME.CurrentEnemyType, SetNewEnemyX, SetNewEnemyY);
    }

    // TOGGLE INTERFACE
    if(MouseButtonRight_pressed && ME.ShowInterface)
    {
      ME.ShowInterface = false;
    }
    // DELETE TILE OR ENEMY OR PLATFORM
    else if(MouseButtonRight_pressed && !ME.ShowInterface)
    {
      int DeleteX = (int)((MouseX+ME.StagePosX)/TS.Tile_Width);
      int DeleteY = (int)((MouseY+ME.StagePosY)/TS.Tile_Height);
      LOOP_Editor_Stages_Delete_Tile(DeleteX, DeleteY);
    }

    if(SDL_GetTicks() - timecounter_StageEditor > ScrollSpeed)
    {
      timecounter_StageEditor = SDL_GetTicks();
      if(Move_Right){ME.StagePosX +=32;}
      if(Move_Left) {ME.StagePosX -=32;}
      if(ME.StagePosX < 0){ME.StagePosX = 0;}
      if(ME.StagePosX > Stage_End){ME.StagePosX = Stage_End;}
    }
    Update_Screen();  // draw the scene
  }
  GV.Mode = GameModeTemp;
  getInput();  // make sure no "pressed key" is carried over to the menu...
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Draw_Stage()
{
  int x,y,z;
  int ScreenWidthTiles = (int)(GV.Screen_Width/16);

  for(y=0; y<StageC64.StageHeight; y++)
  {
    for(x=0; x<ScreenWidthTiles; x++)
    {
      TILE_Draw((x*TS.Tile_Width), y*TS.Tile_Height, 0); // DRAW BACKGROUND
      if(ME.BackgroundColour == 0){TILE_Draw((x*TS.Tile_Width), y*TS.Tile_Height, 0);}
      if(ME.BackgroundColour == 1){TILE_Draw((x*TS.Tile_Width), y*TS.Tile_Height, 40);}
    }
  }

  // DRAW STAGE
  for(y=0; y<StageC64.StageHeight; y++)
  {
    for(x=(int)(ME.StagePosX/16); x<(int)(ME.StagePosX/16)+ScreenWidthTiles+1; x++)
    {
      if(ME.TileNumber[x][y] !=0)
      {
        TILE_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, ME.TileNumber[x][y]);
        if(ME.DrawGrid)
        {
          if(TileType[ME.TileNumber[x][y]].Exit)   {INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_EXIT);}
          if(TileType[ME.TileNumber[x][y]].Lethal) {INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_LETHAL);}
          //if(TileType[ME.TileNumber[x][y]].Solid) {INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_SOLID);}
        }
      }
      // DRAW SEPERATORS FOR CREATOR-MODULES
      if(x==31 || x==63 || x==95 || x==127 || x==159 || x==191 || x==223 || x==255)
      {
        INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_MODULE_END);
      }
      // DRAW SEPERATORS FOR CREATOR-MODULES
    }
  }

  // DRAW OVERLAY-INFOS
  for(y=0; y<StageC64.StageHeight; y++)
  {
    for(x=(int)(ME.StagePosX/16); x<(int)(ME.StagePosX/16)+ScreenWidthTiles+1; x++)
    {
      // MARK CORNER OF STONES
      if(ME.TileNumber[x][y] == 501){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);}
      if(ME.TileNumber[x][y] == 480){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);}
      if(ME.TileNumber[x][y] == 480){Print((x*TS.Tile_Width)-ME.StagePosX+0, (y*TS.Tile_Height)+18,0,0,"POWER");}
      if(ME.TileNumber[x][y] == 560){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);}
      if(ME.TileNumber[x][y] == 640){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);}
      if(ME.TileNumber[x][y] == 640){Print((x*TS.Tile_Width)-ME.StagePosX+0, (y*TS.Tile_Height)+18,0,0,"COINS");}
      if(ME.TileNumber[x][y] == 511){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);}
      if(ME.TileNumber[x][y] == 566){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);}
      if(ME.TileNumber[x][y] == 250){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // LAVA
      if(ME.TileNumber[x][y] == 514){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // BARREL
      if(ME.TileNumber[x][y] == 10){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // LITTLE FLAMES
      if(ME.TileNumber[x][y] == 80){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // WARP BLOCK
      if(ME.TileNumber[x][y] == 587){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // UNBREAKABLE BLOCK
      if(ME.TileNumber[x][y] == 678){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // UNBREAKABLE SQUARE
      if(ME.TileNumber[x][y] == 6){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // FIRE
      if(ME.TileNumber[x][y] == 32){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // SPIKE
      if(ME.TileNumber[x][y] == 87){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // PLANT
      if(ME.TileNumber[x][y] == 50){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // ORNAMENT
      if(ME.TileNumber[x][y] == 104){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // CLOUD
      if(ME.TileNumber[x][y] == 16){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // BARREL (NARROW)
      if(ME.TileNumber[x][y] == 83){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // BARREL (FLAT)
      if(ME.TileNumber[x][y] == 636){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // PIPE
      if(ME.TileNumber[x][y] == 3){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // COIN
      if(ME.TileNumber[x][y] == 720){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // EXIT 1
      if(ME.TileNumber[x][y] == 726){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // EXIT 2
      if(ME.TileNumber[x][y] == 729){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // EXIT 3
      if(ME.TileNumber[x][y] == 272){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // EXIT 4
      if(ME.TileNumber[x][y] == 775){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // GROUND 1
      if(ME.TileNumber[x][y] == 780){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // GROUND 2
      if(ME.TileNumber[x][y] == 783){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // GROUND 3
      if(ME.TileNumber[x][y] == 788){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // GROUND 4
      if(ME.TileNumber[x][y] == 791){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // GROUND 5
      if(ME.TileNumber[x][y] == 794){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // GROUND 6
      if(ME.TileNumber[x][y] == 797){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // GROUND 7
      if(ME.TileNumber[x][y] == 672){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // BRICKS
      if(ME.TileNumber[x][y] == 674){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // BRICKS (END LEFT)
      if(ME.TileNumber[x][y] == 676){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // BRICKS (END RIGHT)
      if(ME.TileNumber[x][y] == 630){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // BRIDGE 1
      if(ME.TileNumber[x][y] == 633){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // BRIDGE 2
      if(ME.TileNumber[x][y] == 160){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // PLANT 1
      if(ME.TileNumber[x][y] == 170){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // PLANT 2
      if(ME.TileNumber[x][y] == 177){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // PLANT 3
      if(ME.TileNumber[x][y] == 181){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // PLANT 4
      if(ME.TileNumber[x][y] == 186){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // PLANT 5
      if(ME.TileNumber[x][y] == 60){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // PLANT 6
      if(ME.TileNumber[x][y] == 29){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // PLANT 7
      if(ME.TileNumber[x][y] == 269){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // FINAL COIN
      if(ME.TileNumber[x][y] == 670){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // DIRTY BRICKS
      if(ME.TileNumber[x][y] == 581){INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_DELETE);} // DROP STONE
      if(ME.TileNumber[x][y] == 581){Print((x*TS.Tile_Width)-ME.StagePosX+0, (y*TS.Tile_Height)+18,0,0,"STONE");}
      // MARK CORNER OF STONES

      for(z=0; z<4; z++)
      {
        if(x==ME.StartPositionX_Tile[z] &&y==ME.StartPositionY_Tile[z])
        {
          if(ME.CurrentStartPosition != z)
          {
            INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_CHECKPOINT);
            INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, (y-1)*TS.Tile_Height, INTERFACE_MARK_CHECKPOINT);
            INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, (y-2)*TS.Tile_Height, INTERFACE_MARK_CHECKPOINT);
            //INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, (y-3)*TS.Tile_Height, INTERFACE_MARK_CHECKPOINT);
          }
          if(ME.CurrentStartPosition == z)
          {
            INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, y*TS.Tile_Height, INTERFACE_MARK_CHECKPOINT_ACTIVE);
            INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, (y-1)*TS.Tile_Height, INTERFACE_MARK_CHECKPOINT_ACTIVE);
            INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, (y-2)*TS.Tile_Height, INTERFACE_MARK_CHECKPOINT_ACTIVE);
            //INTERFACE_Tile_Draw((x*TS.Tile_Width)-ME.StagePosX, (y-3)*TS.Tile_Height, INTERFACE_MARK_CHECKPOINT_ACTIVE);
          }
          if(z>0){PrintInt((x*TS.Tile_Width)-ME.StagePosX+4, (y*TS.Tile_Height)+4,0,0,z);}
          if(z==0){Print((x*TS.Tile_Width)-ME.StagePosX+4, (y*TS.Tile_Height)+4,0,0,"S");}
        }
      }
    }
  }

  if(ME.Platform_inUse)
  {
    LOOP_Editor_Stages_SPRITE_Platform_Draw();
  }

  if(ME.DrawGrid)
  {
    SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 255);
    for(x=0; x < GV.ScreenHeightTiles+1; x++)
    {
      SDL_RenderDrawLine(gRenderer, 0, x*TS.Tile_Height, GV.Screen_Width, x*TS.Tile_Height);
    }
    for(x=0; x < GV.ScreenWidthTiles; x++)
    {
      SDL_RenderDrawLine(gRenderer, x*TS.Tile_Width, 0, x*TS.Tile_Width, GV.Screen_Height);
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Load_Stage(int StageNumber)
{
  int x,y;

  ME.StagePosX = 0;
  ME.Stage = StageNumber;

  for(y = 0; y < 30; y++)
  {
    for (x = 0; x < 256; x++)
    {
      ME.TileNumber[x][y] = StageCache_C64.TileNumber[StageNumber][x][y];
    }
  }

  for (x = 0; x < MAX_NUM_ENEMIES; x++)
  {
    ME.Enemy_Type[x] = StageCache_C64.Enemy_Type[StageNumber][x];
    ME.Enemy_InUse[x] = StageCache_C64.Enemy_InUse[StageNumber][x];
    ME.Enemy_Direction[x] = StageCache_C64.Enemy_Direction[StageNumber][x];
    ME.Enemy_PosX[x] = StageCache_C64.Enemy_PosX[StageNumber][x];
    ME.Enemy_PosY[x] = StageCache_C64.Enemy_PosY[StageNumber][x];
    ME.Enemy_Alive[x] = true;

    // SAFETY MEASURE
    if(ME.Enemy_PosX[x] < 0){ME.Enemy_PosX[x]=0;}
    if(ME.Enemy_PosX[x] > StageC64.StageWidthPixels){ME.Enemy_PosX[x]=0;}
    if(ME.Enemy_PosY[x] < 0){ME.Enemy_PosY[x]=0;}
    if(ME.Enemy_PosY[x] > StageC64.StageHeightPixels){ME.Enemy_PosY[x]=0;}
    if(ME.Enemy_Direction[x] > 1){ME.Enemy_Direction[x] = 0;}
    if(ME.Enemy_Type[x] > 16){ME.Enemy_Type[x] = 0;}
    if(ME.Enemy_Type[x] < 0){ME.Enemy_Type[x] = 0;}
    // SAFETY MEASURE
  }

  for (x = 0; x < 4; x++)
  {
    ME.StartPositionX_Tile[x] = (int)(StageCache_C64.StartPositionX[StageNumber][x]/TS.Tile_Width);
    ME.StartPositionY_Tile[x] = (int)(StageCache_C64.StartPositionY[StageNumber][x]/TS.Tile_Height);
  }

  ME.BackgroundColour = StageCache_C64.BackgroundColour[StageNumber];
  ME.TileType = StageCache_C64.TileType[StageNumber];

  ME.Platform_inUse = StageCache_C64.PlatformInUse[StageNumber];
  ME.Platform_Start_X = StageCache_C64.PlatformX[StageNumber];
  ME.Platform_Start_Y = StageCache_C64.PlatformY[StageNumber];
  ME.Platform_End_X = ME.Platform_Start_X;
  ME.Platform_End_Y = ME.Platform_Start_Y - StageCache_C64.PlatformPathLength[StageNumber];

/*
  // NEEDED TO LOAD "OLD"-STAGE SETS
  ME.Platform_End_Y = ME.Platform_Start_Y - ((int)(StageCache_C64.PlatformPathLength[StageNumber]/TS.Tile_Height)*2);

  ME.Platform_Start_X = (int)(ME.Platform_Start_X/TS.Tile_Width)*2;
  ME.Platform_Start_Y = (int)(ME.Platform_Start_Y/TS.Tile_Height)*2;

  ME.Platform_End_X = (int)(ME.Platform_End_X/TS.Tile_Width)*2;
  ME.Platform_End_Y = (int)(ME.Platform_End_Y/TS.Tile_Height)*2;
*/
}

// ##############################################
// ##############################################
// ##############################################
