#include "globals.h"

// ##############################################
// ##############################################
// ##############################################


void show_DebugInfos()
{
  // Print(0,0,0,0,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  // Print(0,10,0,0,"abcdefghijklmnopqrstuvwxyz");
  // Print(0,20,0,0," 0123456789ÄÖÜäöü");
  // Print(0,30,0,0,".,?!'-+*/\"()=:");

  //GV.RefreshMS = (int) (SDL_GetTicks()-GV.FPS_Counter);
  //Print(0,GV.Screen_Height-10,0,0,"FPS:");
  //PrintInt(50,GV.Screen_Height-10,2,0, (int) (1000/GV.RefreshMS));
  //GV.FPS_Counter = SDL_GetTicks();

  //Print(100,GV.Screen_Height-10,2,0, "F2-reload   F3-next   F4-previous");
  //PrintInt(0, GV.Screen_Height-20, 0, 0, GV.RefreshMS);

/*
  int i;
  int j = 10;
  for(i = 0; i < MAX_NUM_ENEMIES; i++)
  {
    PrintInt(10,  j+(i*10), 0, 0, i);
    PrintInt(50, j+(i*10), 0, 0, Enemy[i].PosX);
    PrintInt(150, j+(i*10), 0, 0, Enemy[i].PosY);
    PrintInt(200, j+(i*10), 0, 0, Enemy[i].StartPosX);
    PrintInt(250, j+(i*10), 0, 0, Enemy[i].StartPosY);
    PrintInt(300, j+(i*10), 0, 0, Enemy[i].inUse);
    PrintInt(350, j+(i*10), 0, 0, Enemy[i].Direction);
    PrintInt(400, j+(i*10), 0, 0, Enemy[i].Type);
  }
*/

  // PrintInt(50,GV.Screen_Height-20,2,0, PC.TargetEnemy);
  // PrintInt(50,GV.Screen_Height-30,2,0, StageC64.TileType);

  // Print(0,GV.Screen_Height-20,0,0,"VEL:");
  // if(PC.RunVelocity > -1){PrintInt(50, GV.Screen_Height-20, 2, 0, (int)PC.RunVelocity);}
  // if(PC.RunVelocity < 0) {PrintInt(40, GV.Screen_Height-20, 2, 0, (int)PC.RunVelocity);}

  // Print(0,GV.Screen_Height-30,0,0,"VEL:");
  // if(PC.JumpVelocity > -1){PrintInt(50, GV.Screen_Height-30, 2, 0, (int)PC.JumpVelocity);}
  // if(PC.JumpVelocity < 0) {PrintInt(40, GV.Screen_Height-30, 2, 0, (int)PC.JumpVelocity);}



  //PrintInt(0,GV.Screen_Height-40,2,0, PC.StagePosX);
}

// ##############################################
// ##############################################
// ##############################################
