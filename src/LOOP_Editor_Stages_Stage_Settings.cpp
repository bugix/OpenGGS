#include "globals.h"



// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Change_Stage_Settings()
{
  if(!ME.SingleTileMode && ME.ElementGroup == 1)
  {
    if(MouseY > 69 && MouseY < 81 && MouseX > 459 && MouseX < 561){ME.TileType = 0;}
    if(MouseY > 81 && MouseY < 93 && MouseX > 459 && MouseX < 561){ME.TileType = 1;}
    if(MouseY > 93 && MouseY < 105 && MouseX > 459 && MouseX < 561){ME.TileType = 2;}
    if(MouseY > 105 && MouseY < 117 && MouseX > 459 && MouseX < 561){ME.TileType = 3;}

    if(MouseY > 154 && MouseY < 166 && MouseX > 459 && MouseX < 561)
    {
      ME.Platform_inUse = !ME.Platform_inUse;
    }

    if(MouseY > 166 && MouseY < 178 && MouseX > 459 && MouseX < 561 && ME.Platform_inUse)
    {
      // RESET PLATFORM
      ME.Platform_Start_X = 10;
      ME.Platform_Start_Y = 10;
      ME.Platform_End_X = ME.Platform_Start_X;
      ME.Platform_End_Y = ME.Platform_Start_Y - 3;
      ME.ShowInterface = false;
    }

    if(MouseY > 190 && MouseY < 202 && MouseX > 459 && MouseX < 561)
    {
      ME.BackgroundColour = 0;
    }

    if(MouseY > 202 && MouseY < 214 && MouseX > 459 && MouseX < 561)
    {
      ME.BackgroundColour = 1;
    }
  }
}
