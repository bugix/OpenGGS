#include "globals.h"

//SDL_Texture* tilesTexture = NULL;
SDL_Texture* fontTexture = NULL;
SDL_Texture* PlayerTexture = NULL;
SDL_Texture* TilesTexture = NULL;
SDL_Texture* EnemiesTexture = NULL;
SDL_Texture* InterfaceTexture = NULL;
SDL_Texture* PowerUpTexture = NULL;
SDL_Surface* tmpSurface;

// ##############################################
// ##############################################
// ##############################################

void loadTextures()
{
  // KILL TEXTURES - OTHERWISE MEMORY USAGE EXPLODES
  // WHEN LOADING DIFFERENT TEXTURES
  SDL_DestroyTexture(fontTexture);
  SDL_DestroyTexture(PlayerTexture);
  SDL_DestroyTexture(TilesTexture);
  SDL_DestroyTexture(EnemiesTexture);
  SDL_DestroyTexture(InterfaceTexture);
  SDL_DestroyTexture(PowerUpTexture);

  tmpSurface = IMG_Load( FileName.Font );
  SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 255, 0, 255 ) ); // Rosa wird transparent
  fontTexture = SDL_CreateTextureFromSurface( gRenderer, tmpSurface );
  SDL_FreeSurface( tmpSurface );

  tmpSurface = IMG_Load( FileName.Player );
  SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 255, 0, 255 ) ); // Rosa wird transparent
  PlayerTexture = SDL_CreateTextureFromSurface( gRenderer, tmpSurface );
  SDL_FreeSurface( tmpSurface );

  tmpSurface = IMG_Load( FileName.Tiles );
  SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 255, 0, 255 ) ); // Rosa wird transparent
  TilesTexture = SDL_CreateTextureFromSurface( gRenderer, tmpSurface );
  SDL_FreeSurface( tmpSurface );

  tmpSurface = IMG_Load( FileName.Enemies );
  SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 255, 0, 255 ) ); // Rosa wird transparent
  EnemiesTexture = SDL_CreateTextureFromSurface( gRenderer, tmpSurface );
  SDL_FreeSurface( tmpSurface );

  tmpSurface = IMG_Load( FileName.Interface );
  SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 255, 0, 255 ) ); // Rosa wird transparent
  InterfaceTexture = SDL_CreateTextureFromSurface( gRenderer, tmpSurface );
  SDL_FreeSurface( tmpSurface );

  tmpSurface = IMG_Load( FileName.PowerUp );
  SDL_SetColorKey( tmpSurface, SDL_TRUE, SDL_MapRGB( tmpSurface->format, 255, 0, 255 ) ); // Rosa wird transparent
  PowerUpTexture = SDL_CreateTextureFromSurface( gRenderer, tmpSurface );
  SDL_FreeSurface( tmpSurface );


}

// ##############################################
// ##############################################
// ##############################################
