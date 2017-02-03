#include "globals.h"

Text_Offset_Def Splashscreen;
Text_Offset_Def WarpScreen;

// ##############################################
// ##############################################
// ##############################################

void LOOP_Gameloop_Splashscreen()
{
  int GameModeTemp = GV.Mode;

  GV.Mode = MODE_SPLASHSCREEN;

  Splashscreen.x_off = (GV.Screen_Width/2) - 50;
  Splashscreen.y_off = (GV.Screen_Height/2)- 24;

  bool ExitSplashscreen = false;

  while(!QuitProgram && !QuitToMenu && !ExitSplashscreen)
  {
    getInput();

    if(e.type == SDL_QUIT){QuitProgram = true;}
    if(Key_ESCAPE_pressed || Joy_ESCAPE_pressed){ExitSplashscreen = true;}
    if(Key_LALT && Key_ENTER_pressed)          {toggleScreenmode();}

    if(Key_ENTER_pressed || Key_CTRL_pressed || Joy_OK_pressed) {ExitSplashscreen = true;}

    Update_Screen();  // draw the scene
  }

  GV.Mode = GameModeTemp;
  getInput();  // make sure no "pressed key" is carried over to the menu...
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Gameloop_Splashscreen_Draw()
{
  if(PC.Lives > 0)
  {
    Print(Splashscreen.x_off,8+Splashscreen.y_off,0,0,"GET READY");
    Print(Splashscreen.x_off,20+Splashscreen.y_off,0,0,"PLAYER");
    if(PC.Stage < 10)
    {
      Print(Splashscreen.x_off,32+Splashscreen.y_off,0,0,"STAGE 0");
      PrintInt(70+Splashscreen.x_off,32+Splashscreen.y_off,0,0,PC.Stage);
    }
    if(PC.Stage > 9)
    {
      Print(Splashscreen.x_off,32+Splashscreen.y_off,0,0,"STAGE");
      PrintInt(60+Splashscreen.x_off,32+Splashscreen.y_off,0,0,PC.Stage);
    }
  }
  if(PC.Lives < 1)
  {
    Print_Big(16+Splashscreen.x_off,8+Splashscreen.y_off,0,0,"GAME");
    Print_Big(16+Splashscreen.x_off,24+Splashscreen.y_off,0,0,"OVER");
  }
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Gameloop_Warpscreen()
{
  int GameModeTemp = GV.Mode;

  PC.WarpCounter = 0;
  GV.Mode = MODE_WARPSCREEN;

  WarpScreen.x_off = (GV.Screen_Width/2) - 50;
  WarpScreen.y_off = (GV.Screen_Height/2)- 24;

  PC.Stage += 3;
  if(PC.Stage > 33){PC.Stage = 33;}

  bool ExitSplashscreen = false;

  while(!QuitProgram && !QuitToMenu && !ExitSplashscreen)
  {
    getInput();

    if(e.type == SDL_QUIT){QuitProgram = true;}
    if(Key_ESCAPE_pressed || Joy_ESCAPE_pressed){ExitSplashscreen = true;}
    if(Key_LALT && Key_ENTER_pressed)          {toggleScreenmode();}

    if(Key_ENTER_pressed || Key_CTRL_pressed || Joy_OK_pressed) {ExitSplashscreen = true;}

    Update_Screen();  // draw the scene
  }
  GV.Mode = GameModeTemp;
  STAGE_Load(PC.Stage, 0, false, false);
  getInput();  // make sure no "pressed key" is carried over to the menu...
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Gameloop_Warpscreen_Draw()
{
  Print(WarpScreen.x_off,8-24+WarpScreen.y_off,0,0,"WARPING!!!");

  Print(WarpScreen.x_off,8+WarpScreen.y_off,0,0,"GET READY");
  Print(WarpScreen.x_off,20+WarpScreen.y_off,0,0,"PLAYER");
  if(PC.Stage < 10)
  {
    Print(WarpScreen.x_off,32+WarpScreen.y_off,0,0,"STAGE 0");
    PrintInt(70+WarpScreen.x_off,32+WarpScreen.y_off,0,0,PC.Stage);
  }
  if(PC.Stage > 9)
  {
    Print(WarpScreen.x_off,32+WarpScreen.y_off,0,0,"STAGE");
    PrintInt(60+WarpScreen.x_off,32+WarpScreen.y_off,0,0,PC.Stage);
  }
}
