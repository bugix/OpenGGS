#include "globals.h"

Enemy_Type_Def Enemy_Type[30];
EnemyVariables EV;
Enemy_Def Enemy[MAX_NUM_ENEMIES];

// ##############################################
// ##############################################
// ##############################################

void ENEMIES_Define()
{
  int x, y;

  EV.Frame = 0;

  // RESET ENEMIES
  for(x=0; x<MAX_NUM_ENEMIES; x++)
  {
    Enemy[x].PosX = x*25;
    Enemy[x].PosY = 100;
    Enemy[x].Direction = NPC_RIGHT;
    Enemy[x].Type = 1;
    Enemy[x].Alive = true;
    Enemy[x].inUse = false;
    Enemy[x].RunVelocity = 0;
    Enemy[x].JumpVelocity = 0;
    Enemy[x].Active = false;
  }


  // LOADING ENEMIES' DIMENSIONS
  //  1 = OWL
  //  2 = EYE
  //  3 = JELLY
  //  4 = CRAB
  //  5 = BEE
  //  6 = BUG
  //  7 = BALL
  //  8 = HOOK 1
  //  9 = HOOK 2
  // 10 = HOOK 3
  // 11 = ROBIN HOOD
  // 12 = DRAGON
  // 13 = SPIDER
  // 14 = PIRANHA
  // 15 = PIPE
  FILE* stagefile;
  Uint32 temparray[690];  // 15*46
  stagefile = fopen(FileName.EnemiesDefinition,  "r");
  if (stagefile == NULL)
  {
    fprintf(stderr,"PLAYER DIMENSIONS NOT FOUND!!!");
  }
  else
  {
    for (x = 0; x < 690; x++){fscanf(stagefile, "%i,", &temparray[x]);}
    x = 0;

    for(y=1; y<16; y++)
    {
      Enemy_Type[y].JumpStrength = 0;
      Enemy_Type[y].Flying = false;
      Enemy_Type[y].FallOfCliffs = false;
      Enemy_Type[y].Walker = true;
      Enemy_Type[y].RunStrength = 10;
      Enemy_Type[y].ColWidth = temparray[x]; x++;
      Enemy_Type[y].ColHeight = temparray[x]; x++;
      Enemy_Type[y].Stompable = true;
      Enemy_Type[y].Shootable = true;
      Enemy_Type[y].SpecialPath_Dragon = false;
      Enemy_Type[y].SpecialPath_Spider = false;

      Enemy_Type[y].FrameX[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameY[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameW[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameH[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameX[NPC_RIGHT][NPC_FRAME2][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameY[NPC_RIGHT][NPC_FRAME2][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameW[NPC_RIGHT][NPC_FRAME2][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameH[NPC_RIGHT][NPC_FRAME2][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameX[NPC_RIGHT][NPC_FRAME3][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameY[NPC_RIGHT][NPC_FRAME3][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameW[NPC_RIGHT][NPC_FRAME3][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameH[NPC_RIGHT][NPC_FRAME3][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameX[NPC_RIGHT][NPC_FRAME4][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameY[NPC_RIGHT][NPC_FRAME4][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameW[NPC_RIGHT][NPC_FRAME4][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameH[NPC_RIGHT][NPC_FRAME4][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameX[NPC_DEAD][NPC_DEAD][NPC_DEAD] = temparray[x]; x++;
      Enemy_Type[y].FrameY[NPC_DEAD][NPC_DEAD][NPC_DEAD] = temparray[x]; x++;
      Enemy_Type[y].FrameW[NPC_DEAD][NPC_DEAD][NPC_DEAD] = temparray[x]; x++;
      Enemy_Type[y].FrameH[NPC_DEAD][NPC_DEAD][NPC_DEAD] = temparray[x]; x++;
      Enemy_Type[y].FrameX[NPC_LEFT][NPC_FRAME1][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameY[NPC_LEFT][NPC_FRAME1][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameW[NPC_LEFT][NPC_FRAME1][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameH[NPC_LEFT][NPC_FRAME1][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameX[NPC_LEFT][NPC_FRAME2][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameY[NPC_LEFT][NPC_FRAME2][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameW[NPC_LEFT][NPC_FRAME2][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameH[NPC_LEFT][NPC_FRAME2][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameX[NPC_LEFT][NPC_FRAME3][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameY[NPC_LEFT][NPC_FRAME3][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameW[NPC_LEFT][NPC_FRAME3][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameH[NPC_LEFT][NPC_FRAME3][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameX[NPC_LEFT][NPC_FRAME4][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameY[NPC_LEFT][NPC_FRAME4][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameW[NPC_LEFT][NPC_FRAME4][NPC_ALIVE] = temparray[x]; x++;
      Enemy_Type[y].FrameH[NPC_LEFT][NPC_FRAME4][NPC_ALIVE] = temparray[x]; x++;
      x+=8; // TWO MORE FRAMES NOT YET IMPLEMENTED
    }
  }
  fclose(stagefile);

  // OWL
  Enemy_Type[1].FallOfCliffs = true;

  // EYE
  Enemy_Type[2].FallOfCliffs = true;

  // CRAB
  Enemy_Type[4].FallOfCliffs = true;

  // BEE
  Enemy_Type[5].Walker = false;
  Enemy_Type[5].Flying = true;

  // BALL
  Enemy_Type[7].Walker = false;
  Enemy_Type[7].JumpStrength = 18;
  Enemy_Type[7].Stompable = false;
  Enemy_Type[7].Shootable = false;

  // Hook 1
  Enemy_Type[8].FallOfCliffs = true;

  // Hook 2
  Enemy_Type[9].FallOfCliffs = true;

  // Hook 3
  Enemy_Type[10].FallOfCliffs = false;

  // DRAGON
  Enemy_Type[12].Walker = false;
  Enemy_Type[12].Stompable = false;
  Enemy_Type[12].Shootable = false;
  Enemy_Type[12].SpecialPath_Dragon = true;

  // SPIDER
  Enemy_Type[13].Walker = false;
  Enemy_Type[13].Stompable = false;
  Enemy_Type[13].Shootable = false;
  Enemy_Type[13].SpecialPath_Spider = true;

  // PIRANHA
  Enemy_Type[14].Walker = false;
  Enemy_Type[14].JumpStrength = 28;
  Enemy_Type[14].Stompable = false;
  Enemy_Type[14].Shootable = false;

  // PIPE (HAS MORE FRAMES!!!)
  Enemy_Type[15].FallOfCliffs = true;
  Enemy_Type[15].Stompable = false;
  Enemy_Type[15].Shootable = false;

  Enemy_Type[15].FrameW[NPC_RIGHT][NPC_FRAME5][NPC_ALIVE] = Enemy_Type[15].FrameW[NPC_LEFT][NPC_FRAME3][NPC_ALIVE];
  Enemy_Type[15].FrameH[NPC_RIGHT][NPC_FRAME5][NPC_ALIVE] = Enemy_Type[15].FrameH[NPC_LEFT][NPC_FRAME3][NPC_ALIVE];
  Enemy_Type[15].FrameW[NPC_RIGHT][NPC_FRAME6][NPC_ALIVE] = Enemy_Type[15].FrameW[NPC_LEFT][NPC_FRAME2][NPC_ALIVE];
  Enemy_Type[15].FrameH[NPC_RIGHT][NPC_FRAME6][NPC_ALIVE] = Enemy_Type[15].FrameH[NPC_LEFT][NPC_FRAME2][NPC_ALIVE];
  Enemy_Type[15].FrameW[NPC_RIGHT][NPC_FRAME7][NPC_ALIVE] = Enemy_Type[15].FrameW[NPC_LEFT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameH[NPC_RIGHT][NPC_FRAME7][NPC_ALIVE] = Enemy_Type[15].FrameH[NPC_LEFT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameW[NPC_RIGHT][NPC_FRAME8][NPC_ALIVE] = Enemy_Type[15].FrameW[NPC_LEFT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameH[NPC_RIGHT][NPC_FRAME8][NPC_ALIVE] = Enemy_Type[15].FrameH[NPC_LEFT][NPC_FRAME1][NPC_ALIVE];

  Enemy_Type[15].FrameX[NPC_RIGHT][NPC_FRAME5][NPC_ALIVE] = Enemy_Type[15].FrameX[NPC_LEFT][NPC_FRAME3][NPC_ALIVE];
  Enemy_Type[15].FrameY[NPC_RIGHT][NPC_FRAME5][NPC_ALIVE] = Enemy_Type[15].FrameY[NPC_LEFT][NPC_FRAME3][NPC_ALIVE];
  Enemy_Type[15].FrameX[NPC_RIGHT][NPC_FRAME6][NPC_ALIVE] = Enemy_Type[15].FrameX[NPC_LEFT][NPC_FRAME2][NPC_ALIVE];
  Enemy_Type[15].FrameY[NPC_RIGHT][NPC_FRAME6][NPC_ALIVE] = Enemy_Type[15].FrameY[NPC_LEFT][NPC_FRAME2][NPC_ALIVE];
  Enemy_Type[15].FrameX[NPC_RIGHT][NPC_FRAME7][NPC_ALIVE] = Enemy_Type[15].FrameX[NPC_LEFT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameY[NPC_RIGHT][NPC_FRAME7][NPC_ALIVE] = Enemy_Type[15].FrameY[NPC_LEFT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameX[NPC_RIGHT][NPC_FRAME8][NPC_ALIVE] = Enemy_Type[15].FrameX[NPC_LEFT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameY[NPC_RIGHT][NPC_FRAME8][NPC_ALIVE] = Enemy_Type[15].FrameY[NPC_LEFT][NPC_FRAME1][NPC_ALIVE];

  Enemy_Type[15].FrameW[NPC_LEFT][NPC_FRAME5][NPC_ALIVE] = Enemy_Type[15].FrameW[NPC_RIGHT][NPC_FRAME3][NPC_ALIVE];
  Enemy_Type[15].FrameH[NPC_LEFT][NPC_FRAME5][NPC_ALIVE] = Enemy_Type[15].FrameH[NPC_RIGHT][NPC_FRAME3][NPC_ALIVE];
  Enemy_Type[15].FrameW[NPC_LEFT][NPC_FRAME6][NPC_ALIVE] = Enemy_Type[15].FrameW[NPC_RIGHT][NPC_FRAME2][NPC_ALIVE];
  Enemy_Type[15].FrameH[NPC_LEFT][NPC_FRAME6][NPC_ALIVE] = Enemy_Type[15].FrameH[NPC_RIGHT][NPC_FRAME2][NPC_ALIVE];
  Enemy_Type[15].FrameW[NPC_LEFT][NPC_FRAME7][NPC_ALIVE] = Enemy_Type[15].FrameW[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameH[NPC_LEFT][NPC_FRAME7][NPC_ALIVE] = Enemy_Type[15].FrameH[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameW[NPC_LEFT][NPC_FRAME8][NPC_ALIVE] = Enemy_Type[15].FrameW[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameH[NPC_LEFT][NPC_FRAME8][NPC_ALIVE] = Enemy_Type[15].FrameH[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE];

  Enemy_Type[15].FrameX[NPC_LEFT][NPC_FRAME5][NPC_ALIVE] = Enemy_Type[15].FrameX[NPC_RIGHT][NPC_FRAME3][NPC_ALIVE];
  Enemy_Type[15].FrameY[NPC_LEFT][NPC_FRAME5][NPC_ALIVE] = Enemy_Type[15].FrameY[NPC_RIGHT][NPC_FRAME3][NPC_ALIVE];
  Enemy_Type[15].FrameX[NPC_LEFT][NPC_FRAME6][NPC_ALIVE] = Enemy_Type[15].FrameX[NPC_RIGHT][NPC_FRAME2][NPC_ALIVE];
  Enemy_Type[15].FrameY[NPC_LEFT][NPC_FRAME6][NPC_ALIVE] = Enemy_Type[15].FrameY[NPC_RIGHT][NPC_FRAME2][NPC_ALIVE];
  Enemy_Type[15].FrameX[NPC_LEFT][NPC_FRAME7][NPC_ALIVE] = Enemy_Type[15].FrameX[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameY[NPC_LEFT][NPC_FRAME7][NPC_ALIVE] = Enemy_Type[15].FrameY[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameX[NPC_LEFT][NPC_FRAME8][NPC_ALIVE] = Enemy_Type[15].FrameX[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE];
  Enemy_Type[15].FrameY[NPC_LEFT][NPC_FRAME8][NPC_ALIVE] = Enemy_Type[15].FrameY[NPC_RIGHT][NPC_FRAME1][NPC_ALIVE];

  // DEFINE  ColWidthHalf
  for(y=1;y<17;y++){Enemy_Type[y].ColWidthHalf = (int)(Enemy_Type[y].ColWidth/2);}
}

// ##############################################
// ##############################################
// ##############################################
