#include "globals.h"

Text_Offset_Def Credits;

// ##############################################
// ##############################################
// ##############################################

void LOOP_Credits()
{
  int GameModeTemp = GV.Mode;
  GV.Mode = MODE_CREDITS;

  Credits.x_off = 20;
  Credits.y_off = 20;

  while(!QuitProgram && !QuitToMenu)
  {
    getInput();
    INPUT_General();

    if(Key_ESCAPE_pressed || Joy_ESCAPE_pressed){QuitToMenu = true;}

    Update_Screen();  // draw the scene
  }
  GV.Mode = GameModeTemp;
  getInput();  // make sure no "pressed key" is carried over to the menu...
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Credits_Draw()
{
  Print(16+Credits.x_off,8+Credits.y_off,2,0,"CREDITS");
  Print(16+Credits.x_off,32+Credits.y_off,2,0,"The Great Giana Sisters (C64)");
  Print(16+Credits.x_off,44+Credits.y_off,0,0,"1987 Softgold/Rainbow Arts");
  Print(16+Credits.x_off,56+Credits.y_off,0,0,"Written:      Armin Gessert");
  Print(16+Credits.x_off,68+Credits.y_off,0,0,"Artwork:      Manfred Trenz");
  Print(16+Credits.x_off,80+Credits.y_off,0,0,"Music:        Chris Huelsbeck");

  Print(16+Credits.x_off,104+Credits.y_off,2,0,"OpenGGS 2.0 - OpenGGS Maker");
  Print(16+Credits.x_off,116+Credits.y_off,0,0,"Written:      RomanH");
  Print(16+Credits.x_off,128+Credits.y_off,0,0,"Artwork:      RomanH");
  Print(16+Credits.x_off,140+Credits.y_off,0,0,"Soundeffects: RomanH, Kenney (opengameart.org)");
  Print(16+Credits.x_off,152+Credits.y_off,0,0,"Music:        Alejandro Altimari (puch666)");

  Print(16+Credits.x_off,176+Credits.y_off,2,0,"Interface elements");
  Print(16+Credits.x_off,188+Credits.y_off,0,0,"Clipart:      openclipart.org (Tango-Collection)");
  Print(16+Credits.x_off,200+Credits.y_off,0,0,"Soundeffects: RomanH");
  Print(16+Credits.x_off,212+Credits.y_off,0,0,"              Kenney (opengameart.org)");

  Print(16+Credits.x_off,236+Credits.y_off,2,0,"Thanks to everybody involved in porting");
  Print(16+Credits.x_off,248+Credits.y_off,2,0,"the game to different plattforms!!!");
}
