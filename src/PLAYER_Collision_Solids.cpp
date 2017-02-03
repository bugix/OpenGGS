#include "globals.h"

bool StopRunningLeft;
bool StopRunningRight;
bool PC_Collision_Down();
bool PC_Collision_Up();
bool PC_Collision_Right();
bool PC_Collision_Left();
bool PC_Collision_Down_Stone();
int StonePCStandsOn;

// ##############################################
// ##############################################
// ##############################################

void PC_Check_Tilecollision()
{
  StopRunningLeft = false;
  StopRunningRight = false;
  PC.OnGround = false;
  PC.HitWall = false;
  PC.WallGrinding = false;
  PC.OnPlatform = false;


  if(PC_Collision_Right())
  {
    PC.RunVelocity = 0;
    PC.HitWall = true;
    if(!GV.PixelPerfectRunning){PC.PosX -= ((PC.PosX+PC.ColWidthHalf) % TS.Tile_Width);} // NOT NEEDED ANYMORE SINCE MOVEMENT IS PIXEL PERFECT
  }


  if(PC_Collision_Left())
  {
    PC.RunVelocity = 0;
    PC.HitWall = true;
    if(!GV.PixelPerfectRunning){PC.PosX += TS.Tile_Width-1-((PC.PosX-PC.ColWidthHalf) % TS.Tile_Width);} // NOT NEEDED ANYMORE SINCE MOVEMENT IS PIXEL PERFECT
  }



  if(PC_Collision_Down())
  {
    PC.JumpOnGoing = false;
    PC.OnGround = true;
    PC.OnGroundDelay = PC.OnGroundDelayMax;
    PC.JumpVelocity = 0;
    //if(!PC.OnPlatform){PC.PosY -= PC.PosY % TS.Tile_Height;} // NOT NEEDED ANYMORE SINCE DOWNWARD MOVEMENT IS PIXEL PERFECT
    if(PC.OnPlatform) {PC.PosY = Platform.PosY;}
  }


  if(PC_Collision_Down_Stone())
  {
    PC.JumpOnGoing = false;
    PC.OnGround = true;
    //PC.JumpVelocity = 0;
    PC.PosY = Sprite_DropStone[StonePCStandsOn].PosY;
  }

  if(PC_Collision_Up())
  {
    PC.JumpOnGoing = false;
    PC.JumpVelocity = 0;
  }


  if(PC_Collision_Exit())
  {
    PC.Exit_Reached = true;
  }


}

// ##############################################
// ##############################################
// ##############################################

bool PC_Collision_Down()
{
  bool ReturnValue = false;


  if(PC.JumpVelocity < 0 && PC.RunVelocity == 0)
  {
    if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+1)/TS.Tile_Width)][(int)(PC.PosY/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-LEFT
       TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthQuart)/TS.Tile_Width)] [(int)(PC.PosY/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)]                    [(int)(PC.PosY/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-CENTER
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthQuart)/TS.Tile_Width)] [(int)(PC.PosY/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-1)/TS.Tile_Width)][(int)(PC.PosY/TS.Tile_Height)]].Solid)     // CHECK BOTTOM-RIGHT
    {
      ReturnValue = true;
    }
  }

  // PREVENTS GETTING STUCK ON THE WALL
  if(PC.JumpVelocity < 0 && PC.RunVelocity > 0)
  {
    if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+1)/TS.Tile_Width)][(int)(PC.PosY/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-LEFT
       TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthQuart)/TS.Tile_Width)] [(int)(PC.PosY/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)]                    [(int)(PC.PosY/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-CENTER
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthQuart)/TS.Tile_Width)] [(int)(PC.PosY/TS.Tile_Height)]].Solid)     // CHECK BOTTOM-RIGHT
    {ReturnValue = true;}
  }

  if(PC.JumpVelocity < 0 && PC.RunVelocity < 0)
  {
    if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthQuart)/TS.Tile_Width)] [(int)(PC.PosY/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)]                    [(int)(PC.PosY/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-CENTER
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthQuart)/TS.Tile_Width)] [(int)(PC.PosY/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-1)/TS.Tile_Width)][(int)(PC.PosY/TS.Tile_Height)]].Solid)     // CHECK BOTTOM-RIGHT
    {
      ReturnValue = true;
    }
  }


  // MAKE IT EASIER TO STAND ON LEDGE <<--- NEEDED!!! OTHERWISE PLAYER SINK INTO GROUND - BUT WHY???
  if(TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-1)/TS.Tile_Width)][(int)(PC.PosY/TS.Tile_Height)]].Solid &&
    !TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-1)/TS.Tile_Width)][(int)((PC.PosY-1)/TS.Tile_Height)]].Solid)
    {ReturnValue = true;}

  if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+1)/TS.Tile_Width)][(int)(PC.PosY/TS.Tile_Height)]].Solid &&
    !TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+1)/TS.Tile_Width)][(int)((PC.PosY-1)/TS.Tile_Height)]].Solid)
    {ReturnValue = true;}
  // MAKE IT EASIER TO STAND ON LEDGE


  // CHECK WHETHER PLAYER STANDS ON CRUMBLING GROUND
  if(PC.JumpVelocity < 0)
  {
    if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthQuart)/TS.Tile_Width)][(int)(PC.PosY/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)]              [(int)(PC.PosY/TS.Tile_Height)]].Solid ||   // CHECK BOTTOM-CENTER
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthQuart)/TS.Tile_Width)][(int)(PC.PosY/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-1)/TS.Tile_Width)][(int)(PC.PosY/TS.Tile_Height)]].Solid)     // CHECK BOTTOM-RIGHT
    {
      Check_Switch_Tile_Down((int)((PC.PosX-PC.ColWidthHalf+1)/TS.Tile_Width), (int)(PC.PosY/TS.Tile_Height));
      Check_Switch_Tile_Down((int)((PC.PosX)/TS.Tile_Width), (int)(PC.PosY/TS.Tile_Height));
      Check_Switch_Tile_Down((int)((PC.PosX+PC.ColWidthHalf-1)/TS.Tile_Width), (int)(PC.PosY/TS.Tile_Height));
    }
  }


  if(PC.PosY > 479){ReturnValue = true; PC.gotKilled = true;}  // DON'T FALL OFF SCREEN
  if(PC.PosY < 0){ReturnValue = false;}  // DON'T GET STUCK ON TOP OF SCREEN

  if(Platform.inUse)
  {
    if(PC.PosY > Platform.PosY-2 &&
       PC.PosY < Platform.PosY + 10 && //+Platform.h &&
       PC.PosX+PC.ColHeightHalf > Platform.PosX &&
       PC.PosX-PC.ColHeightHalf < Platform.PosX+Platform.w)
    {
       PC.OnPlatform = true;
       ReturnValue = true;
    }
  }

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool PC_Collision_Up()
{
  bool ReturnValue = false;
  if(PC.JumpVelocity > 0 && PC.RunVelocity == 0) // JUMPING UP
  {
    if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+1)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthQuart)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)]              [(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||   // CHECK TOP-CENTER
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthQuart)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-1)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid)
    {ReturnValue = true;}
  }

  if(PC.JumpVelocity > 0 && PC.RunVelocity > 0) // JUMPING UP
  {
    if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf+1)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthQuart)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)]              [(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||   // CHECK TOP-CENTER
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthQuart)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid)
    {ReturnValue = true;}
  }

  if(PC.JumpVelocity > 0 && PC.RunVelocity < 0) // JUMPING UP
  {
    if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthQuart)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)(PC.PosX/TS.Tile_Width)]              [(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||   // CHECK TOP-CENTER
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthQuart)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid ||
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf-1)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeight)/TS.Tile_Height)]].Solid)
    {ReturnValue = true;}
  }

  if(Platform.inUse)
  {
    if(PC.PosY-PC.ColHeight > Platform.PosY &&
       PC.PosY-PC.ColHeight < Platform.PosY+Platform.h &&
       PC.PosX+PC.ColHeightHalf > Platform.PosX &&
       PC.PosX-PC.ColHeightHalf < Platform.PosX+Platform.w)
    {
       PC.PosY +=3; // FOR SOME REASON PC GET'S STUCK OTHERWISE
       ReturnValue = true;
    }
  }

  PC_Collision_CoinBlock();
  PC_Collision_PowerUpBlock();
  if(PC.Mode == PC_MODE2)
  {
    PC_Collision_CoinBlockHelmet();
    PC_Collision_Breakable();
    PC_Collision_DropStone();
  }
  PC_Collision_WarpStone();

  // MAKING SURE YOU CAN JUMP OUT OF SCREEN
  if(PC.PosY < PC.ColHeight){ReturnValue = false;}

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool PC_Collision_Right()
{
  bool ReturnValue = false;
  if(PC.RunVelocity > 0 && (PC.PosY > PC.ColHeight || !GV.PixelPerfectRunning)) // RUNNING TO THE RIGHT
  {
    if(TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeightHalf)/TS.Tile_Height)]].Solid ||   // CHECK CENTER-RIGHT
       TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-1)/TS.Tile_Height)]].Solid)   // CHECK BOTTOM-RIGHT
    {
      ReturnValue = true;
      if(GV.PixelPerfectRunning){PC.PosX--;}
      if(PC.AccellRight){PC.WallGrinding = true;}
    }
    if(PC.JumpVelocity < -5)
    {
      ReturnValue = false;
      if(TileType[StageC64.TileNumber[(int)((PC.PosX+PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-1)/TS.Tile_Height)]].Solid)   // CHECK BOTTOM-RIGHT
      {
        ReturnValue = true;
        if(PC.AccellRight){PC.WallGrinding = true;}
      }
    }
  }


  // CHECK COLLISION WITH STONES
  int i = 0;
  for(i=1; i<30; i++)
  {
    if(Sprite_DropStone[i].inUse)
    {
      if(PC.PosX+PC.ColWidthHalf-1 > Sprite_DropStone[i].PosX &&
         PC.PosX+PC.ColWidthHalf-1 < Sprite_DropStone[i].PosX + Sprite_DropStone[i].w &&
         PC.PosY-1 < Sprite_DropStone[i].PosY + Sprite_DropStone[i].h &&
         PC.PosY-1 > Sprite_DropStone[i].PosY)
      {
         ReturnValue = true;
      }
    }
  }


  // MAKING SURE YOU CAN JUMP OUT OF SCREEN
  if(PC.PosY < PC.ColHeight){ReturnValue = false;}

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool PC_Collision_Left()
{
  bool ReturnValue = false;
  if(PC.RunVelocity < 0 && (PC.PosY > PC.ColHeight || !GV.PixelPerfectRunning)) // RUNNING TO THE LEFT
  {
    if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-PC.ColHeightHalf)/TS.Tile_Height)]].Solid ||   // CHECK CENTER-LEFT
       TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-1)/TS.Tile_Height)]].Solid)   // CHECK BOTTOM-LEFT
    {
      ReturnValue = true;
      if(GV.PixelPerfectRunning){PC.PosX++;}
      if(PC.AccellLeft){PC.WallGrinding = true;}
    }
    if(PC.JumpVelocity < -5)
    {
      ReturnValue = false;
      if(TileType[StageC64.TileNumber[(int)((PC.PosX-PC.ColWidthHalf)/TS.Tile_Width)][(int)((PC.PosY-1)/TS.Tile_Height)]].Solid)   // CHECK BOTTOM-RIGHT
      {
        ReturnValue = true;
        if(PC.AccellRight){PC.WallGrinding = true;}
      }
    }
  }

  // CHECK COLLISION WITH STONES
  int i = 0;
  for(i=1; i<30; i++)
  {
    if(Sprite_DropStone[i].inUse)
    {
      if(PC.PosX-PC.ColWidthHalf+1 > Sprite_DropStone[i].PosX &&
         PC.PosX-PC.ColWidthHalf+1 < Sprite_DropStone[i].PosX + Sprite_DropStone[i].w &&
         PC.PosY-1 < Sprite_DropStone[i].PosY + Sprite_DropStone[i].h &&
         PC.PosY-1 > Sprite_DropStone[i].PosY)
      {
         ReturnValue = true;
      }
    }
  }

  // MAKING SURE YOU CAN JUMP OUT OF SCREEN
  if(PC.PosY < PC.ColHeight){ReturnValue = false;}

  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################

bool PC_Collision_Down_Stone()
{
  bool ReturnValue = false;

  int i = 0;

  for(i=1; i<30; i++)
  {
    // CHECK IF PLAYER JUMP ONTO STONE
    if(Sprite_DropStone[i].inUse)
    {
      if(PC.PosY > Sprite_DropStone[i].PosY - 1 &&
         PC.PosY < Sprite_DropStone[i].PosY + 10 &&
         PC.PosX+PC.ColWidthHalf-3 > Sprite_DropStone[i].PosX &&
         PC.PosX-PC.ColWidthHalf+3 < Sprite_DropStone[i].PosX+Sprite_DropStone[1].w)
      {
         ReturnValue = true;
         StonePCStandsOn = i;
      }

      // LIFT PLAYER ONTO STONE IF CRUSHED BY STONE
      if(PC.PosY-1 < Sprite_DropStone[i].PosY + Sprite_DropStone[i].h &&
         PC.PosY-1 > Sprite_DropStone[i].PosY)
      {
        if((PC.PosX-PC.ColWidthHalf+10 > Sprite_DropStone[i].PosX &&
            PC.PosX-PC.ColWidthHalf+10 < Sprite_DropStone[i].PosX + Sprite_DropStone[i].w) ||
           (PC.PosX+PC.ColWidthHalf-10 > Sprite_DropStone[i].PosX &&
            PC.PosX+PC.ColWidthHalf-10 < Sprite_DropStone[i].PosX + Sprite_DropStone[i].w))
        {
           ReturnValue = true;
           StonePCStandsOn = i;
        }
      }

    }
  }
  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################
