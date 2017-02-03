#include "globals.h"

TileTypesDefinition TileType[NUMBER_OF_TILES];
TileSheet_Type TS;

// ##############################################
// ##############################################
// ##############################################

void TILES_Define()
{
  int j, i, k;
  for(j=0;j<TS.Height;j++)
  {
    for(i=0;i<TS.Width;i++)
    {
      k = i + (j * TS.Width);
      TileType[k].x = i*TS.Tile_Width;
      TileType[k].y = j*TS.Tile_Height;
      TileType[k].w = TS.Tile_Width;
      TileType[k].h = TS.Tile_Height;
      TileType[k].Solid = true;
      TileType[k].Exit = false;
      TileType[k].Lethal = false;
      TileType[k].Fire = false;
      TileType[k].Coin = false;
      TileType[k].ColourChanging = false;
      TileType[k].SubStageEntrance = false;
      TileType[k].WarpStone = false;
    }
  }
}

// ##############################################
// ##############################################
// ##############################################
