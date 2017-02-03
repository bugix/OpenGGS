#include "globals.h"

void PC_Check_Collision_PowerUp(int PowerUpNumber);
void PC_Check_Collision_Enemy(int EnemyNumber);

// ##############################################
// ##############################################
// ##############################################

void PC_Check_Collision_Sprites()
{
  int i;
  for(i=1; i<10; i++)
  {
    if(Sprite_PowerUp[i].Active)
    {
      PC_Check_Collision_PowerUp(i);
    }
  }

  for(i=0; i<MAX_NUM_ENEMIES; i++)
  {
    if(Enemy[i].inUse)
    {
      PC_Check_Collision_Enemy(i);
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void PC_Check_Collision_PowerUp(int PowerUpNumber)
{
  //QuitToMenu = true;
  bool PowerUpCollected = false;

  int bx1 = Sprite_PowerUp[PowerUpNumber].PosX;
  int bx2 = Sprite_PowerUp[PowerUpNumber].PosX+Sprite_PowerUp[PowerUpNumber].w;
  int by1 = Sprite_PowerUp[PowerUpNumber].PosY;
  int by2 = Sprite_PowerUp[PowerUpNumber].PosY+Sprite_PowerUp[PowerUpNumber].h;

  if(bx1 > PC.x1 && bx1 < PC.x3 && by1 > PC.y1 && by1 < PC.y3){PowerUpCollected = true;}
  if(bx2 > PC.x1 && bx2 < PC.x3 && by2 > PC.y1 && by2 < PC.y3){PowerUpCollected = true;}
  if(bx1 > PC.x1 && bx1 < PC.x3 && by2 > PC.y1 && by2 < PC.y3){PowerUpCollected = true;}
  if(bx2 > PC.x1 && bx2 < PC.x3 && by1 > PC.y1 && by1 < PC.y3){PowerUpCollected = true;}

  if(PowerUpCollected)
  {
    AUDIO_Sound_Play(AUDIO_DING);
    Sprite_PowerUp[PowerUpNumber].Active = false;
    if(PC.PowerUp<8){PC_PowerUp_Set(PowerUpNumber);}
    //if(PC.PowerUp>0){PC.Mode = PC_MODE2;}
  }
}

// ##############################################
// ##############################################
// ##############################################

void PC_Check_Collision_Enemy(int EnemyNumber)
{
  int PCX1 = PC.PosX-PC.ColWidthHalf;
  int PCX2 = PC.PosX+PC.ColWidthHalf;
  int PCY1 = PC.PosY-PC.ColHeight;
  int PCY2 = PC.PosY-1;
  int PCY3 = PC.PosY-PC.ColHeightQuart; // LOWER HALF OF PLAYER
  int EX1 = Enemy[EnemyNumber].PosX-Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf;
  int EX2 = Enemy[EnemyNumber].PosX+Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf;
  int EY1 = Enemy[EnemyNumber].PosY-Enemy_Type[Enemy[EnemyNumber].Type].ColHeight;
  int EY2 = Enemy[EnemyNumber].PosY;

  if((PCX2 > EX1 && PCX2 < EX2) || (PCX1 > EX1 && PCX1 < EX2))
  {

    if((PCY2 > EY1 && PCY2 < EY2) || (PCY3 > EY1 && PCY3 < EY2)) // LOWER QUART OF PLAYER
    {
      if((PC.JumpVelocity < 0 || PC.JumpVelocity == PC.JumpStrength) && Enemy[EnemyNumber].Alive && Enemy_Type[Enemy[EnemyNumber].Type].Stompable)
      {
        // STOMP THE ENEMY
        Enemy[EnemyNumber].JumpVelocity = 0;
        Enemy[EnemyNumber].Alive = false;
        PC.JumpOnGoing = true;
        PC.JumpVelocity = PC.JumpStrength;
        AUDIO_Sound_Play(AUDIO_STOMP);
      }
    }
    if((PCY2 > EY1 && PCY2 < EY2) || (PCY1 > EY1 && PCY1 < EY2)) // FULL HEIGHT OF PLAYER
    {
      if(Enemy[EnemyNumber].Alive && !PC.GodMode){PC.gotKilled = true;}
    }
  }
}

// ##############################################
// ##############################################
// ##############################################
