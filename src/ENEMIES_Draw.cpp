#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void ENEMIES_Draw()
{
  int x;
  for (x = 0; x < MAX_NUM_ENEMIES; x++)
  {
    if(Enemy[x].inUse){ENEMY_Draw(x);}
  }
}

// ##############################################
// ##############################################
// ##############################################

void ENEMY_Draw(int EnemyNumber)
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  int AnimationFrame;
  AnimationFrame = EV.Frame_4;
  if(Enemy[EnemyNumber].Type == 15){AnimationFrame = EV.Frame_7;}


  if(Enemy[EnemyNumber].inUse && Enemy[EnemyNumber].Active)
  {
    SrcRect.x = Enemy_Type[1].FrameX[NPC_LEFT][AnimationFrame][NPC_ALIVE];
    SrcRect.y = Enemy_Type[1].FrameY[NPC_LEFT][AnimationFrame][NPC_ALIVE];
    SrcRect.w = Enemy_Type[1].FrameW[NPC_LEFT][AnimationFrame][NPC_ALIVE];
    SrcRect.h = Enemy_Type[1].FrameH[NPC_LEFT][AnimationFrame][NPC_ALIVE];

    if(Enemy[EnemyNumber].Type < 16)
    {
      SrcRect.x = Enemy_Type[Enemy[EnemyNumber].Type].FrameX[Enemy[EnemyNumber].Direction][AnimationFrame][NPC_ALIVE];
      SrcRect.y = Enemy_Type[Enemy[EnemyNumber].Type].FrameY[Enemy[EnemyNumber].Direction][AnimationFrame][NPC_ALIVE];
      SrcRect.w = Enemy_Type[Enemy[EnemyNumber].Type].FrameW[Enemy[EnemyNumber].Direction][AnimationFrame][NPC_ALIVE];
      SrcRect.h = Enemy_Type[Enemy[EnemyNumber].Type].FrameH[Enemy[EnemyNumber].Direction][AnimationFrame][NPC_ALIVE];

      if(!Enemy[EnemyNumber].Alive)
      {
        SrcRect.x = Enemy_Type[Enemy[EnemyNumber].Type].FrameX[NPC_DEAD][NPC_DEAD][NPC_DEAD];
        SrcRect.y = Enemy_Type[Enemy[EnemyNumber].Type].FrameY[NPC_DEAD][NPC_DEAD][NPC_DEAD];
        SrcRect.w = Enemy_Type[Enemy[EnemyNumber].Type].FrameW[NPC_DEAD][NPC_DEAD][NPC_DEAD];
        SrcRect.h = Enemy_Type[Enemy[EnemyNumber].Type].FrameH[NPC_DEAD][NPC_DEAD][NPC_DEAD];
      }
    }

    DstRect.w = SrcRect.w;
    DstRect.h = SrcRect.h;
    DstRect.x = Enemy[EnemyNumber].PosX-(int)(SrcRect.w/2)-PC.StagePosX;
    DstRect.y = Enemy[EnemyNumber].PosY-SrcRect.h;
    SDL_RenderCopyEx(gRenderer, EnemiesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
    //int GrabberX = DstRect.x;
    //int GrabberY = DstRect.y;
    //PrintInt(GrabberX, GrabberY, 0,0, Enemy[EnemyNumber].Type);
    //PrintInt(GrabberX, GrabberY+10, 0,0,EnemyNumber);
    //PrintInt(GrabberX, GrabberY+20, 0,0,Enemy[EnemyNumber].Direction);
  }
}

// ##############################################
// ##############################################
// ##############################################
