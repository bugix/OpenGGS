#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void Animation()
{
  int x, y;

    if(SDL_GetTicks() - timecounter_Animation_Tiles_Fast > 200)
    {
      timecounter_Animation_Tiles_Fast = SDL_GetTicks();
      TS.NextFrame = true;

      EV.Frame++;
      if(EV.Frame > 7){EV.Frame = 0;}
      EV.Frame_4++;
      if(EV.Frame_4 > 3){EV.Frame_4 = 0;}
      EV.Frame_7++;
      if(EV.Frame_7 > 6){EV.Frame_7 = 0;}

      ME.Frame_3++;
      if(ME.Frame_3 > 2){ME.Frame_3 = 0;}
      ME.Frame_4++;
      if(ME.Frame_4 > 3){ME.Frame_4 = 0;}
      ME.Frame_6++;
      if(ME.Frame_6 > 5){ME.Frame_6 = 0;}
      ME.Frame_8++;
      if(ME.Frame_8 > 7){ME.Frame_8 = 0;}
      if(ShowVolume_Music > 0){ShowVolume_Music--;}
      if(ShowVolume_Sound > 0){ShowVolume_Sound--;}
    }

    if(SDL_GetTicks() - timecounter_TileSwitch > 1)
    {
      timecounter_TileSwitch = SDL_GetTicks();
      for(y=0; y<StageC64.StageHeight; y++)
      {
        for(x=(int)(PC.StagePosX/16); x<(int)(PC.StagePosX/16)+GV.ScreenWidthTiles+1; x++)
        {
          if(StageC64.AnimationCounter[x][y] > 0){StageC64.AnimationCounter[x][y]--;}
        }
      }
      if(Sprite_Bullet.ExplosionAnimation>0){Sprite_Bullet.ExplosionAnimation--;}
      if(PC.MorphingCounter > 0)            {PC.MorphingCounter--;}
      if(PC.WarpCounter > 0)                {PC.WarpCounter--;}
      if(PC.OnGroundDelay > 0)              {PC.OnGroundDelay--;}
      if(GV.TempMusicOffCounter > 0)        {GV.TempMusicOffCounter--;}



/*
      for(y = 0; y < 30; y++)
      {
        for (x = 0; x < 256; x++)
        {
          if(StageC64.AnimationCounter[x][y] > 0){StageC64.AnimationCounter[x][y]--;}
        }
      }
*/
    }



}

// ##############################################
// ##############################################
// ##############################################
