
// ##############################################
// ##############################################
// ##############################################

extern void init();                    //Starts up SDL and creates window
extern void close();                   //Frees media and shuts down SDL
void loadTextures();

// ##############################################
// ##############################################
// ##############################################

//extern SDL_Texture* tilesTexture;
extern SDL_Texture* fontTexture;
extern SDL_Texture* PlayerTexture;
extern SDL_Texture* TilesTexture;
extern SDL_Texture* EnemiesTexture;
extern SDL_Texture* InterfaceTexture;
extern SDL_Texture* PowerUpTexture;

extern SDL_Window* gWindow;     //The window we'll be rendering to
extern SDL_Renderer* gRenderer; //The window renderer

// ##############################################
// ##############################################
// ##############################################

