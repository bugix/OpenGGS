#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void SwitchTileToNextFrame(int x, int y)
{
  // CRUMBLING GROUND
       if(StageC64.TileNumber[x][y] > 567 && StageC64.TileNumber[x][y] < 572 && StageC64.AnimationCounter[x][y] == 0)  {StageC64.TileNumber[x][y] += 2; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  else if(StageC64.TileNumber[x][y] > 571 && StageC64.TileNumber[x][y] < 574 && StageC64.AnimationCounter[x][y] == 0) {StageC64.TileNumber[x][y] = 0;}



  // BLINK OF COIN BLOCK
  if(StageC64.TileNumber[x][y] == 563 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 587; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 564 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 588; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 565 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 589; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 603 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 627; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 604 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 628; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 605 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 629; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}



  // BREAKABLE BLOCK
  if(StageC64.TileNumber[x][y] == 507 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 0;}
  if(StageC64.TileNumber[x][y] == 508 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 0;}
  if(StageC64.TileNumber[x][y] == 509 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 0;}
  if(StageC64.TileNumber[x][y] == 547 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 0;}
  if(StageC64.TileNumber[x][y] == 548 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 0;}
  if(StageC64.TileNumber[x][y] == 549 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 0;}

  if(StageC64.TileNumber[x][y] == 504 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 507; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 505 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 508; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 506 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 509; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 544 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 547; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 545 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 548; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 546 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 549; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}



  // BLINK OF 5-COIN BLOCK
  if(StageC64.TileNumber[x][y] == 643 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3;StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 644 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3;StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 645 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3;StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 683 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3;StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 684 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3;StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 685 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3;StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}

  if(StageC64.TileNumber[x][y] == 649 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 650 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 651 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 689 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 690 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 691 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}

  if(StageC64.TileNumber[x][y] == 655 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 656 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 657 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 695 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 696 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 697 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}

  if(StageC64.TileNumber[x][y] == 661 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 662 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 663 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 701 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 702 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 703 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] += 3; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}

  if(StageC64.TileNumber[x][y] == 667 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 587; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 668 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 588; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 669 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 589; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 707 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 627; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 708 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 628; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
  if(StageC64.TileNumber[x][y] == 709 && StageC64.AnimationCounter[x][y] == 0){StageC64.TileNumber[x][y] = 629; StageC64.AnimationCounter[x][y] = World.TileSwitchSpeed;}
}

// ##############################################
// ##############################################
// ##############################################
