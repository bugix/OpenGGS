#include "globals.h"

void ENEMY_Gravity(int EnemyNumber);
void ENEMY_Walk(int EnemyNumber);
void ENEMY_Move_Dragon(int EnemyNumber);
void ENEMY_Move_Spider(int EnemyNumber);

// ##############################################
// ##############################################
// ##############################################

void ENEMIES_Move()
{
  int x;

  for (x = 1; x < MAX_NUM_ENEMIES; x++)  // CRASH IF x = 0!!
  {

    ENEMY_Check_Tilecollision(x);

    if(Enemy[x].Active && Enemy[x].inUse){ENEMY_Gravity(x);}

    if((Enemy_Type[Enemy[x].Type].Walker || Enemy_Type[Enemy[x].Type].Flying) && Enemy[x].Active && Enemy[x].inUse)
    {ENEMY_Walk(x);}

    if(Enemy_Type[Enemy[x].Type].JumpStrength != 0 && Enemy[x].Active && Enemy[x].inUse)
    {ENEMY_Jump(x);}
    //if((Enemy[x].PosX - PC.PosX) < (100+GV.Screen_Width/2)){Enemy[x].Active = true;}

    if(Enemy_Type[Enemy[x].Type].SpecialPath_Dragon && Enemy[x].Active && Enemy[x].Alive && Enemy[x].inUse)
    {ENEMY_Move_Dragon(x);}

    if(Enemy_Type[Enemy[x].Type].SpecialPath_Spider && Enemy[x].Active && Enemy[x].Alive && Enemy[x].inUse)
    {ENEMY_Move_Spider(x);}

    // ACTIVATE ENEMIES

    Enemy[x].Active = false;
    if((Enemy[x].PosX - PC.StagePosX) < (GV.Screen_Width+Enemy_Type[Enemy[x].Type].ColWidth) &&
       Enemy[x].inUse)
    {Enemy[x].Active = true;}


    // DEACTIVATE ENEMIES
    if((Enemy[x].PosX - PC.StagePosX) < -100 && Enemy[x].inUse){Enemy[x].Active = false;}

  }
}

// ##############################################
// ##############################################
// ##############################################

void ENEMY_Walk(int EnemyNumber)
{
  if(Enemy[EnemyNumber].Alive)
  {
    if(Enemy[EnemyNumber].Direction == NPC_RIGHT){Enemy[EnemyNumber].RunVelocity += 1.5*World.Friction;}
    if(Enemy[EnemyNumber].Direction == NPC_LEFT) {Enemy[EnemyNumber].RunVelocity -= 1.5*World.Friction;}

    // MAX SPEED
    if(Enemy[EnemyNumber].RunVelocity < -Enemy_Type[Enemy[EnemyNumber].Type].RunStrength){Enemy[EnemyNumber].RunVelocity = -Enemy_Type[Enemy[EnemyNumber].Type].RunStrength;} // MAX SPEED
    if(Enemy[EnemyNumber].RunVelocity > Enemy_Type[Enemy[EnemyNumber].Type].RunStrength) {Enemy[EnemyNumber].RunVelocity = Enemy_Type[Enemy[EnemyNumber].Type].RunStrength;}  // MAX SPEED
    // MAX SPEED

    Enemy[EnemyNumber].PosX += int(Enemy[EnemyNumber].RunVelocity/4);

    if(Enemy[EnemyNumber].PosX > StageC64.StageWidthPixels-30 && Enemy[EnemyNumber].Direction == NPC_RIGHT){ENEMY_Change_Direction(EnemyNumber);}
    if(Enemy[EnemyNumber].PosX < 30 && Enemy[EnemyNumber].Direction == NPC_LEFT){ENEMY_Change_Direction(EnemyNumber);}
  }
}

// ##############################################
// ##############################################
// ##############################################

void ENEMY_Jump(int EnemyNumber)
{
  // START THE JUMP
  if(Enemy[EnemyNumber].PosY > Enemy[EnemyNumber].StartPosY+1)
  {
    Enemy[EnemyNumber].PosY = Enemy[EnemyNumber].StartPosY;
    Enemy[EnemyNumber].JumpVelocity = Enemy_Type[Enemy[EnemyNumber].Type].JumpStrength;
  }

}

// ##############################################
// ##############################################
// ##############################################

void ENEMY_Gravity(int EnemyNumber)
{

  Enemy[EnemyNumber].JumpVelocity -= World.Gravity;

//  if(Enemy[EnemyNumber].JumpVelocity < -World.TerminalVelocity){Enemy[EnemyNumber].JumpVelocity = -World.TerminalVelocity;}

  if(Enemy[EnemyNumber].OnGround &&
     Enemy_Type[Enemy[EnemyNumber].Type].JumpStrength == 0)
  {Enemy[EnemyNumber].JumpVelocity = 0;}  // DON'T FALL THROUGH SOLIDS

  // ADD GRAVITY IF ENEMY ISN'T FLYING
  if(!Enemy_Type[Enemy[EnemyNumber].Type].SpecialPath_Dragon)
  {
    if(!Enemy_Type[Enemy[EnemyNumber].Type].Flying || !Enemy[EnemyNumber].Alive)
    {
      Enemy[EnemyNumber].PosY -= int(Enemy[EnemyNumber].JumpVelocity/2);
    }
  }

  // DEAD DRAGONS FALL TO THE GROUND AS WELL
  if(Enemy_Type[Enemy[EnemyNumber].Type].SpecialPath_Dragon && !Enemy[EnemyNumber].Alive)
  {
    Enemy[EnemyNumber].PosY -= int(Enemy[EnemyNumber].JumpVelocity/2);
  }

  if(Enemy[EnemyNumber].PosY > 800){Enemy[EnemyNumber].PosY=800;}  // MAKE SURE ENEMIES DON'T FALL FOREVER

  if(Enemy[EnemyNumber].PosY > GV.Screen_Height+100 && Enemy_Type[Enemy[EnemyNumber].Type].JumpStrength == 0)
  {
    Enemy[EnemyNumber].PosY = GV.Screen_Height+100;  // MAKE SURE ENEMIES DON'T FALL FOREVER
    Enemy[EnemyNumber].Alive = false;
    Enemy[EnemyNumber].Active = false;
  }

}

// ##############################################
// ##############################################
// ##############################################

void ENEMY_Change_Direction(int EnemyNumber)
{
  Enemy[EnemyNumber].RunVelocity = 0;
  if(Enemy[EnemyNumber].Direction == NPC_LEFT){Enemy[EnemyNumber].Direction = NPC_RIGHT;}
  else
  {
    if(Enemy[EnemyNumber].Direction == NPC_RIGHT){Enemy[EnemyNumber].Direction = NPC_LEFT;}
  }
}

// ##############################################
// ##############################################
// ##############################################

void ENEMY_Move_Dragon(int EnemyNumber)
{
  Enemy[EnemyNumber].MovementCounter++;
  int Vertical = 24;
  int Horizontal = 24;

  if(Enemy[EnemyNumber].MovementCounter < Vertical)
  {
    Enemy[EnemyNumber].PosY -=2;
  }
  if(Enemy[EnemyNumber].MovementCounter > Vertical-1 && Enemy[EnemyNumber].MovementCounter < Vertical+Horizontal)
  {
    Enemy[EnemyNumber].PosX -=2;
  }
  if(Enemy[EnemyNumber].MovementCounter > Vertical+Horizontal-1 && Enemy[EnemyNumber].MovementCounter < Vertical+(2*Horizontal))
  {
    Enemy[EnemyNumber].PosX +=2;
  }
  if(Enemy[EnemyNumber].MovementCounter > Vertical+(2*Horizontal)-1 && Enemy[EnemyNumber].MovementCounter < 2*(Vertical+Horizontal))
  {
    Enemy[EnemyNumber].PosY +=2;
  }
  if(Enemy[EnemyNumber].MovementCounter > (2*(Vertical+Horizontal))-1)
  {
    Enemy[EnemyNumber].MovementCounter = 0;
  }
}

// ##############################################
// ##############################################
// ##############################################

void ENEMY_Move_Spider(int EnemyNumber)
{
  Enemy[EnemyNumber].MovementCounter++;
  int Forward = 50;
  int Back = 25;

  if(Enemy[EnemyNumber].MovementCounter < Forward)
  {
    Enemy[EnemyNumber].Direction = NPC_LEFT;
    if(!ENEMY_Collision_Left(EnemyNumber)){Enemy[EnemyNumber].PosX -=1;}
    if(!ENEMY_Collision_Left(EnemyNumber)){Enemy[EnemyNumber].PosX -=1;}
    if(!ENEMY_Collision_Left(EnemyNumber)){Enemy[EnemyNumber].PosX -=1;}
  }
  if(Enemy[EnemyNumber].MovementCounter > Forward-1 && Enemy[EnemyNumber].MovementCounter < Forward+Back)
  {
    Enemy[EnemyNumber].Direction = NPC_RIGHT;
    if(!ENEMY_Collision_Right(EnemyNumber)){Enemy[EnemyNumber].PosX +=1;}
    if(!ENEMY_Collision_Right(EnemyNumber)){Enemy[EnemyNumber].PosX +=1;}
    if(!ENEMY_Collision_Right(EnemyNumber)){Enemy[EnemyNumber].PosX +=1;}
  }

  if(Enemy[EnemyNumber].MovementCounter > Forward+Back-1)
  {
    Enemy[EnemyNumber].MovementCounter = 0;
  }
}
