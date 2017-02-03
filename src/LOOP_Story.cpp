#include "globals.h"

Text_Offset_Def Story;

// ##############################################
// ##############################################
// ##############################################

void LOOP_Story()
{
  int GameModeTemp = GV.Mode;
  GV.Mode = MODE_STORY;
  Mix_HaltMusic();

  Story.x_off = 20;
  Story.y_off = 20;

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

void LOOP_Story_Draw()
{
  int Line = 12;

  Print(Story.x_off,Story.y_off + (-1*Line),0,0,"Backgroundstory of 'The Great Giana Sisters'");

  Print(Story.x_off,Story.y_off + (2*Line),2,0,"What happened?");
  Print(Story.x_off,Story.y_off + (3*Line),0,0,"One night, when little Giana from Milano was");
  Print(Story.x_off,Story.y_off + (4*Line),0,0,"fast asleep, she has a strange dream.");
  Print(Story.x_off,Story.y_off + (5*Line),0,0,"Everybody dreams weird things at night, but");
  Print(Story.x_off,Story.y_off + (6*Line),0,0,"no one will have experienced situations like");
  Print(Story.x_off,Story.y_off + (7*Line),0,0,"little Giana is about to.");
  Print(Story.x_off,Story.y_off + (8*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (9*Line),0,0,"Giana suddenly finds herself in a strange ");
  Print(Story.x_off,Story.y_off + (10*Line),0,0,"mysterious world, where everything is completly");
  Print(Story.x_off,Story.y_off + (11*Line),0,0,"different. Gravity has almost disappeared -");
  Print(Story.x_off,Story.y_off + (12*Line),0,0,"sometimes one feels like flying away – and");
  Print(Story.x_off,Story.y_off + (13*Line),0,0,"everywhere there are unexplainable buildings");
  Print(Story.x_off,Story.y_off + (14*Line),0,0,"and structures. Old grottos and deserted castles");
  Print(Story.x_off,Story.y_off + (15*Line),0,0,"seem to hide lots of secrets, and frightening and");
  Print(Story.x_off,Story.y_off + (16*Line),0,0,"hideous creatures appear. This wouldn't be too bad,");
  Print(Story.x_off,Story.y_off + (17*Line),0,0,"except that Giana can't leave this world unless she");
  Print(Story.x_off,Story.y_off + (18*Line),0,0,"finds the magic, huge diamond. So she starts");
  Print(Story.x_off,Story.y_off + (19*Line),0,0,"searching for this wonderful jewel.");
  Print(Story.x_off,Story.y_off + (20*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (21*Line),2,0,"However, she is not totally alone, for her little ");
  Print(Story.x_off,Story.y_off + (22*Line),2,0,"sister Maria can dream, too.");
  Print(Story.x_off,Story.y_off + (23*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (24*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (25*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (26*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (27*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (28*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (29*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (30*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (31*Line),0,0,"");
  Print(Story.x_off,Story.y_off + (32*Line),0,0,"");
}

