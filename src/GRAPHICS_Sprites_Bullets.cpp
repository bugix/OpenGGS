#include "globals.h"

bool Sprite_Bullet_Collision_Right();
bool Sprite_Bullet_Collision_Left();
bool Sprite_Bullet_Collision_Bottom();
bool Sprite_Bullet_Collision_Top();
void Sprite_Bullet_Collision_Enemies(int EnemyNumber);
void Sprite_Bullet_Get_TargetEnemy();
void Sprite_Bullet_Collision_PC();

// ##############################################
// ##############################################
// ##############################################

void SPRITE_Bullet_Activate()
{
  if(!Sprite_Bullet.Active)
  {
    PC.TargetEnemy = 0; // RESET TARGET ENEMY BEFORE A SHOT
    if(PC.PowerUp > 3){Sprite_Bullet_Get_TargetEnemy();}

    //FIRE A BULLET
    if(PC.PowerUp > 1)
    {
      AUDIO_Sound_Play(AUDIO_SHOOT);
      Sprite_Bullet.PosY = PC.PosY-PC.ColHeightHalf-PC.ColHeightQuart;
      Sprite_Bullet.Active = true;
      Sprite_Bullet.Direction = PC.Direction;
      if(Sprite_Bullet.Direction == PC_RIGHT)
      {
         Sprite_Bullet.PosX = PC.PosX+PC.ColWidth;
         Sprite_Bullet.RunVelocity = 25;
      }
      if(Sprite_Bullet.Direction == PC_LEFT)
      {
        Sprite_Bullet.PosX = PC.PosX-PC.ColWidth-Sprite_Bullet.w-2;
        Sprite_Bullet.RunVelocity = -25;
      }
      Sprite_Bullet.VerticalDirection = 1;
    }
  }

}

// ##############################################
// ##############################################
// ##############################################

void SPRITE_Bullet_Move()
{
  if(PC.TargetEnemy == 0)
  {
    if(Sprite_Bullet.Direction == PC_RIGHT){Sprite_Bullet.RunVelocity += 1*World.Friction;}
    if(Sprite_Bullet.Direction == PC_LEFT) {Sprite_Bullet.RunVelocity -= 1*World.Friction;}

    // MAX SPEED
    if(Sprite_Bullet.RunVelocity < -Sprite_Bullet.RunStrength){Sprite_Bullet.RunVelocity = -Sprite_Bullet.RunStrength;} // MAX SPEED
    if(Sprite_Bullet.RunVelocity > Sprite_Bullet.RunStrength) {Sprite_Bullet.RunVelocity = Sprite_Bullet.RunStrength;}  // MAX SPEED
    // MAX SPEED

    Sprite_Bullet.PosX += int(Sprite_Bullet.RunVelocity/4);
    if(Sprite_Bullet.VerticalDirection == 1){Sprite_Bullet.PosY += 2;}
    if(Sprite_Bullet.VerticalDirection == 0){Sprite_Bullet.PosY -= 2;}

    // BULLET EXPLODES IF IT HITS A WALL
    if(Sprite_Bullet.Active && PC.PowerUp == 2)
    {
      if(Sprite_Bullet.Direction == PC_RIGHT && Sprite_Bullet_Collision_Right()){Sprite_Bullet.Active = false;}
      if(Sprite_Bullet.Direction == PC_LEFT && Sprite_Bullet_Collision_Left())  {Sprite_Bullet.Active = false;}
      if(Sprite_Bullet.VerticalDirection == 1 && Sprite_Bullet_Collision_Bottom())  {Sprite_Bullet.VerticalDirection = 0;}
      if(Sprite_Bullet.VerticalDirection == 0 && Sprite_Bullet_Collision_Top())  {Sprite_Bullet.VerticalDirection = 1;}
    }

    // BULLET RICOCHETS OFF WALLS
    if(Sprite_Bullet.Active && PC.PowerUp > 2)
    {
      if(Sprite_Bullet.Direction == PC_RIGHT && Sprite_Bullet_Collision_Right()){Sprite_Bullet.RunVelocity = -Sprite_Bullet.RunVelocity; Sprite_Bullet.Direction = PC_LEFT;}
      if(Sprite_Bullet.Direction == PC_LEFT && Sprite_Bullet_Collision_Left())  {Sprite_Bullet.RunVelocity = -Sprite_Bullet.RunVelocity; Sprite_Bullet.Direction = PC_RIGHT;}
      if(Sprite_Bullet.VerticalDirection == 1 && Sprite_Bullet_Collision_Bottom())  {Sprite_Bullet.VerticalDirection = 0;}
      if(Sprite_Bullet.VerticalDirection == 0 && Sprite_Bullet_Collision_Top())  {Sprite_Bullet.VerticalDirection = 1;}
    }
  }

  // HOMING BULLET
  if(PC.TargetEnemy > 0)
  {
    if(Sprite_Bullet.PosX < Enemy[PC.TargetEnemy].PosX){Sprite_Bullet.PosX += 6;}
    if(Sprite_Bullet.PosX > Enemy[PC.TargetEnemy].PosX){Sprite_Bullet.PosX -= 6;}
    if(Sprite_Bullet.PosY < Enemy[PC.TargetEnemy].PosY-Enemy_Type[Enemy[PC.TargetEnemy].Type].ColHeight){Sprite_Bullet.PosY += 6;}
    if(Sprite_Bullet.PosY > Enemy[PC.TargetEnemy].PosY-Enemy_Type[Enemy[PC.TargetEnemy].Type].ColHeight){Sprite_Bullet.PosY -= 6;}
  }


  // CHECK IF BULLET HITS AN ENEMY
  int i;
  for(i=0; i<MAX_NUM_ENEMIES; i++)
  {
    if(Enemy[i].Alive && Enemy_Type[Enemy[i].Type].Shootable)
    {
      Sprite_Bullet_Collision_Enemies(i);
    }
  }

  // CHECK IF BULLET HITS PLAYER
  Sprite_Bullet_Collision_PC();


  // EXPLODE THE BULLET
  if(!Sprite_Bullet.Active)
  {
    Sprite_Bullet.ExplosionAnimation = Sprite_Bullet.ExplosionDuraion;
    Sprite_Bullet.ExplosionX = Sprite_Bullet.PosX;
    Sprite_Bullet.ExplosionY = Sprite_Bullet.PosY;
  }

  // DEACTIVATE BULLET IF OFF SCREEN
  if(Sprite_Bullet.PosY < 0 ||
     Sprite_Bullet.PosY > GV.Screen_Height + 32 ||
     Sprite_Bullet.PosX-PC.StagePosX < 0 ||
     Sprite_Bullet.PosX-PC.StagePosX > GV.Screen_Width + 32)
  {Sprite_Bullet.Active = false;}

}

// ##############################################
// ##############################################
// ##############################################

bool Sprite_Bullet_Collision_Right()
{
  bool ReturnValue = false;

  // CHECK FOR WALLS
  if(TileType[StageC64.TileNumber[(int)((Sprite_Bullet.PosX+Sprite_Bullet.w)/TS.Tile_Width)][(int)((Sprite_Bullet.PosY+Sprite_Bullet.h)/TS.Tile_Height)-1]].Solid)   // CHECK BOTTOM-RIGHT
  {
    ReturnValue = true;
  }

  if(TileType[StageC64.TileNumber[(int)((Sprite_Bullet.PosX+Sprite_Bullet.w)/TS.Tile_Width)][(int)(Sprite_Bullet.PosY/TS.Tile_Height)]].Solid)   // CHECK TOP-RIGHT
  {
    ReturnValue = true;
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool Sprite_Bullet_Collision_Left()
{
  bool ReturnValue = false;

  // CHECK FOR WALLS
  if(TileType[StageC64.TileNumber[(int)(Sprite_Bullet.PosX/TS.Tile_Width)][(int)((Sprite_Bullet.PosY+Sprite_Bullet.h)/TS.Tile_Height)-1]].Solid)   // CHECK BOTTOM-LEFT

  {
    ReturnValue = true;
  }

  if(TileType[StageC64.TileNumber[(int)(Sprite_Bullet.PosX/TS.Tile_Width)][(int)(Sprite_Bullet.PosY/TS.Tile_Height)]].Solid)   // CHECK TOP-LEFT
  {
    ReturnValue = true;
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool Sprite_Bullet_Collision_Bottom()
{
  bool ReturnValue = false;
  int XPOS;
  int YPOS;

  // CHECK FOR WALLS
  if(Sprite_Bullet.Direction == PC_RIGHT){XPOS = (int)((Sprite_Bullet.PosX+Sprite_Bullet.w)/TS.Tile_Width);}

  else {XPOS = (int)(Sprite_Bullet.PosX/TS.Tile_Width);}

  YPOS = (int)((Sprite_Bullet.PosY+Sprite_Bullet.h)/TS.Tile_Height);

  if(TileType[StageC64.TileNumber[XPOS][YPOS]].Solid)   // CHECK BOTTOM-LEFT
  {
    ReturnValue = true;
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool Sprite_Bullet_Collision_Top()
{
  bool ReturnValue = false;
  int XPOS;
  int YPOS;

  // CHECK FOR WALLS
  if(Sprite_Bullet.Direction == PC_RIGHT){XPOS = (int)((Sprite_Bullet.PosX+Sprite_Bullet.w)/TS.Tile_Width);}

  else {XPOS = (int)(Sprite_Bullet.PosX/TS.Tile_Width);}

  YPOS = (int)((Sprite_Bullet.PosY-3)/TS.Tile_Height);

  if(TileType[StageC64.TileNumber[XPOS][YPOS]].Solid)   // CHECK BOTTOM-LEFT
  {
    ReturnValue = true;
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

void Sprite_Bullet_Collision_Enemies(int EnemyNumber)
{
  int PCX1 = Sprite_Bullet.PosX-(Sprite_Bullet.w/2);
  int PCX2 = Sprite_Bullet.PosX+(Sprite_Bullet.w/2);
  int PCY1 = Sprite_Bullet.PosY;
  int PCY2 = Sprite_Bullet.PosY+Sprite_Bullet.h;

  int EX1 = Enemy[EnemyNumber].PosX-Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf;
  int EX2 = Enemy[EnemyNumber].PosX+Enemy_Type[Enemy[EnemyNumber].Type].ColWidthHalf;
  int EY1 = Enemy[EnemyNumber].PosY-Enemy_Type[Enemy[EnemyNumber].Type].ColHeight;
  int EY2 = Enemy[EnemyNumber].PosY;



  if((PCX2 > EX1 && PCX2 < EX2) || (PCX1 > EX1 && PCX1 < EX2))
  {
    if((PCY2 > EY1 && PCY2 < EY2) || (PCY1 > EY1 && PCY1 < EY2)) // FULL HEIGHT OF PLAYER
    {
      Enemy[EnemyNumber].Alive = false;
      Enemy[EnemyNumber].JumpVelocity = 0;
      Sprite_Bullet.Active = false;
      PC.TargetEnemy = 0;
    }
  }

}

// ##############################################
// ##############################################
// ##############################################

void Sprite_Bullet_Get_TargetEnemy()
{
  int EnemyDistance[MAX_NUM_ENEMIES];
  int ShortestDistance = 1000;
  int i;

  for(i=0; i<MAX_NUM_ENEMIES; i++)
  {
    EnemyDistance[i] = -1;
  }

  // FIND CLOSEST ENEMY
  for(i=0; i<MAX_NUM_ENEMIES; i++)
  {
    if(Enemy[i].Active && Enemy[i].Alive && Enemy_Type[Enemy[i].Type].Shootable)
    {
      if(PC.Direction == PC_LEFT){EnemyDistance[i] = Enemy[i].PosX-PC.PosX;}
      if(PC.Direction == PC_RIGHT) {EnemyDistance[i] = PC.PosX-Enemy[i].PosX;}
      if(EnemyDistance[i] < ShortestDistance){ShortestDistance = EnemyDistance[i]; PC.TargetEnemy = i;}
    }
  }

}

// ##############################################
// ##############################################
// ##############################################

void Sprite_Bullet_Collision_PC()
{
  int PCX1 = Sprite_Bullet.PosX-(Sprite_Bullet.w/2);
  int PCX2 = Sprite_Bullet.PosX+(Sprite_Bullet.w/2);
  int PCY1 = Sprite_Bullet.PosY;
  int PCY2 = Sprite_Bullet.PosY+Sprite_Bullet.h;

  int EX1 = PC.PosX-PC.ColWidthHalf;
  int EX2 = PC.PosX+PC.ColWidthHalf;
  int EY1 = PC.PosY-PC.ColHeight;
  int EY2 = PC.PosY-1;


  if((PCX2 > EX1 && PCX2 < EX2) || (PCX1 > EX1 && PCX1 < EX2))
  {
    if((PCY2 > EY1 && PCY2 < EY2) || (PCY1 > EY1 && PCY1 < EY2)) // FULL HEIGHT OF PLAYER
    {
      Sprite_Bullet.Active = false;
      PC.TargetEnemy = 0;
    }
  }

}
