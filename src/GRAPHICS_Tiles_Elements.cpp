#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

int ElementWidth(int ElementNumber)
{
  int ReturnValue = 1;


  if(ElementNumber == 566 ||  // 2x1 CRUMBLING GROUND
     ElementNumber == 3   ||  // 2x2 COIN
     ElementNumber == 670 ||  // 2x2 DIRTY BRICKS
     ElementNumber == 672 ||  // 2x2 BRICKS
     ElementNumber == 674 ||  // 2x2 BRICKS (END LEFT)
     ElementNumber == 676 ||  // 2x2 BRICKS (END RIGHT)
     ElementNumber == 87  ||  // 2x2 PLANT
     ElementNumber == 678 ||  // 2x2 UNBREAKABLE SQUARE
     ElementNumber == 780 ||  // 2x3 GROUND 2
     ElementNumber == 788 ||  // 2x3 GROUND 4
     ElementNumber == 791 ||  // 2x3 GROUND 5
     ElementNumber == 794 ||  // 2x3 GROUND 6
     ElementNumber == 10000)
  {
    ReturnValue = 2;
  }

  if(ElementNumber == 636 ||  // 3x1 PIPE
     ElementNumber == 630 ||  // 3x1 BRIDGE 1
     ElementNumber == 633 ||  // 3x1 BRIDGE 2
     ElementNumber == 250 ||  // 3x1 LAVA/WATER
     ElementNumber == 501 ||  // 3x2 BREAKABLE
     ElementNumber == 480 ||  // 3x2 POWERUP
     ElementNumber == 560 ||  // 3x2 COIN
     ElementNumber == 640 ||  // 3x2 5 COINS
     ElementNumber == 80  ||  // 3x2 WARP BLOCK
     ElementNumber == 581 ||  // 3x2 BREAKABLE
     ElementNumber == 587 ||  // 3x2 UNBREAKABLE
     ElementNumber == 32  ||  // 3x3 SPIKE
     ElementNumber == 186 ||  // 3x3 PLANT 5
     ElementNumber == 797 ||  // 3x3 GROUND 7
     ElementNumber == 50  ||  // 3x3 ORNAMENT
     ElementNumber == 511 ||  // 3x3 BOX
     ElementNumber == 726 ||  // 3x4 Exit 2
     ElementNumber == 269 ||  // 3x5 FINAL COIN
     ElementNumber == 29  ||  // 3x5 PLANT 7




     ElementNumber == 10000)
  {
    ReturnValue = 3;
  }

  if(ElementNumber == 10  ||  // 4x1 FLAMES
     ElementNumber == 83  ||  // 4x2 BARREL (FLAT)
     ElementNumber == 6   ||  // 4x2 FIRE
     ElementNumber == 775 ||  // 4x3 GROUND 1
     ElementNumber == 60  ||  // 4x3 PLANT 6
     ElementNumber == 783 ||  // 4x3 GROUND 3
     ElementNumber == 177 ||  // 4x3 PLANT 3
     ElementNumber == 16  ||  // 4x4 BARREL (NARROW)
     ElementNumber == 729 ||  // 4x4 EXIT 3
     ElementNumber == 10000)
  {
    ReturnValue = 4;
  }

  if(ElementNumber == 104 ||  // 5x2 CLOUD
     ElementNumber == 181 ||  // 5x3 PLANT 3
     ElementNumber == 10000)
  {
    ReturnValue = 5;
  }

  if(ElementNumber == 170 ||  // 6x2 PLANT 2
     ElementNumber == 514 ||  // 6x3 BARREL
     ElementNumber == 720 ||  // 6x4 Exit 1
     ElementNumber == 10000)
  {
    ReturnValue = 6;
  }

  if(ElementNumber == 272 ||  // 8x6 Exit 4
     ElementNumber == 10000)
  {
    ReturnValue = 8;
  }

  if(ElementNumber == 160 ||  // 10x3 PLANT 1
     ElementNumber == 10000)
  {
    ReturnValue = 10;
  }


  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

int ElementHeight(int ElementNumber)
{
  int ReturnValue = 1;
  if(ElementNumber == 566 ||  // 2x1 CRUMBLING GROUND
     ElementNumber == 636 ||  // 3x1 PIPE
     ElementNumber == 630 ||  // 3x1 BRIDGE 1
     ElementNumber == 633 ||  // 3x1 BRIDGE 2
     ElementNumber == 250 ||  // 3x1 LAVA/WATER
     ElementNumber == 10  ||  // 4x1 FLAMES
     ElementNumber == 10000)
  {
    ReturnValue = 1;
  }

  if(ElementNumber == 3   ||  // 2x2 COIN
     ElementNumber == 670 ||  // 2x2 DIRTY BRICKS
     ElementNumber == 672 ||  // 2x2 BRICKS
     ElementNumber == 674 ||  // 2x2 BRICKS (END LEFT)
     ElementNumber == 676 ||  // 2x2 BRICKS (END RIGHT)
     ElementNumber == 87  ||  // 2x2 PLANT
     ElementNumber == 678 ||  // 2x2 UNBREAKABLE SQUARE
     ElementNumber == 501 ||  // 3x2 BREAKABLE
     ElementNumber == 480 ||  // 3x2 POWERUP
     ElementNumber == 560 ||  // 3x2 COIN
     ElementNumber == 640 ||  // 3x2 5 COINS
     ElementNumber == 80  ||  // 3x2 WARP BLOCK
     ElementNumber == 581 ||  // 3x2 BREAKABLE
     ElementNumber == 587 ||  // 3x2 UNBREAKABLE
     ElementNumber == 83  ||  // 4x2 BARREL (FLAT)
     ElementNumber == 6   ||  // 4x2 FIRE
     ElementNumber == 104 ||  // 5x2 CLOUD
     ElementNumber == 170 ||  // 6x2 PLANT 2
     ElementNumber == 10000)
  {
    ReturnValue = 2;
  }

  if(ElementNumber == 780 ||  // 2x3 GROUND 2
     ElementNumber == 788 ||  // 2x3 GROUND 4
     ElementNumber == 791 ||  // 2x3 GROUND 5
     ElementNumber == 794 ||  // 2x3 GROUND 6
     ElementNumber == 32  ||  // 3x3 SPIKE
     ElementNumber == 186 ||  // 3x3 PLANT 5
     ElementNumber == 797 ||  // 3x3 GROUND 7
     ElementNumber == 50  ||  // 3x3 ORNAMENT
     ElementNumber == 511 ||  // 3x3 BOX
     ElementNumber == 775 ||  // 4x3 GROUND 1
     ElementNumber == 60  ||  // 4x3 PLANT 6
     ElementNumber == 783 ||  // 4x3 GROUND 3
     ElementNumber == 177 ||  // 4x3 PLANT 3
     ElementNumber == 181 ||  // 5x3 PLANT 3
     ElementNumber == 514 ||  // 6x3 BARREL
     ElementNumber == 160 ||  // 10x3 PLANT 1
     ElementNumber == 10000)
  {
    ReturnValue = 3;
  }

  if(ElementNumber == 726 ||  // 3x4 Exit 2
     ElementNumber == 720 ||  // 6x4 Exit 1
     ElementNumber == 16  ||  // 4x4 BARREL (NARROW)
     ElementNumber == 729 ||  // 4x4 EXIT 3
     ElementNumber == 10000)
  {
    ReturnValue = 4;
  }

  if(ElementNumber == 269 ||  // 3x5 FINAL COIN
     ElementNumber == 29  ||  // 3x5 PLANT 7
     ElementNumber == 10000)
  {
    ReturnValue = 5;
  }


  if(ElementNumber == 272 ||  // 8x6 Exit 4
     ElementNumber == 10000)
  {
    ReturnValue = 6;
  }

  return ReturnValue;
}
