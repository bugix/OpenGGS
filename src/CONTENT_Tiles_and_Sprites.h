
#define Tile_SmallCoin 45
#define NUMBER_OF_TILES 2320
#define TILESHEET_WIDTH_TILES 40
#define TILESHEET_HEIGHT_TILES 58

void LOOP_Editor_Tiles_Draw();
void LOOP_Editor_Tiles_Interface_Draw();
void LOOP_Editor_Tiles();

void TILES_Define();
void TILE_Draw(int x, int y, int Number);
void TileSheet_Load();
void SwitchTileToNextFrame(int x, int y);
void Check_Switch_Tile_Down(int x, int y);

void SPRITES_Define();
void SPRITES_Draw();
void SPRITES_Move();
void SPRITE_SmallCoin_Activate(int x, int y);
void SPRITE_PowerUp_Activate(int x, int y);
void SPRITE_Bullet_Activate();
void SPRITE_Bullet_Move();

int ElementWidth(int ElementNumber);
int ElementHeight(int ElementNumber);

// ##############################################
// ##############################################
// ##############################################

extern Uint32 timecounter_Animation_Tiles_Fast;
extern Uint32 timecounter_TileSwitch;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int PosX;
  int PosY;
  int ScrollX;
  int ScrollY;
  bool MarkSolids;
  bool MarkExits;
  bool MarkLethals;
  bool MarkFire;
  bool MarkCoins;
  bool MarkCoinBlocks;
  bool MarkBreakables;
  bool MarkPowerUpBlocks;
  bool MarkCoinBlocksHelmet;
  bool MarkColourChanging;
  bool MarkSubStageEntrance;
  bool MarkDropStone;
  bool MarkWarpStone;
} TileEditor_Type;

extern TileEditor_Type TE;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int Tile_Width;
  int Tile_Height;
  int Width;
  int Height;
  int Width_Pixels;
  int Height_Pixels;
  bool Solid[NUMBER_OF_TILES];
  bool Exit[NUMBER_OF_TILES];
  bool Lethal[NUMBER_OF_TILES];
  bool Fire[NUMBER_OF_TILES];
  bool Coin[NUMBER_OF_TILES];
  bool CoinBlock[NUMBER_OF_TILES];
  bool NextFrame;
  bool Breakable[NUMBER_OF_TILES];
  bool PowerUpBlock[NUMBER_OF_TILES];
  bool CoinBlockHelmet[NUMBER_OF_TILES];
  bool ColourChanging[NUMBER_OF_TILES];
  bool SubStageEntrance[NUMBER_OF_TILES];
  bool DropStone[NUMBER_OF_TILES];
  bool WarpStone[NUMBER_OF_TILES];
} TileSheet_Type;

extern TileSheet_Type TS;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int x, y;
  int w, h;
  bool Solid;
  bool Exit;
  bool Lethal;
  bool Fire;
  bool Coin;
  bool CoinBlock;
  bool Breakable;
  bool PowerUpBlock;
  bool CoinBlockHelmet;
  bool ColourChanging;
  bool SubStageEntrance;
  bool DropStone;
  bool WarpStone;
} TileTypesDefinition;
extern TileTypesDefinition TileType[NUMBER_OF_TILES];

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int PosX;
  int PosY;
  float JumpVelocity;
  float RunVelocity;
  bool Active;
} Sprite_SmallCoinDefinition;
extern Sprite_SmallCoinDefinition Sprite_SmallCoin[20];

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int x;
  int y;
  int w;
  int h;
  int PosX;
  int PosY;
  float JumpVelocity;
  float RunVelocity;
  int RunStrength;
  bool Active;
  bool OnGround;
  int Direction;
} Sprite_PowerUp_Definition;
extern Sprite_PowerUp_Definition Sprite_PowerUp[10];

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int x;
  int y;
  int w;
  int h;
  int PosX;
  int PosY;
  int Direction;
  int VerticalDirection;
  bool Active;
  int RunVelocity;
  int RunStrength;
  int ExplosionAnimation;
  int ExplosionX;
  int ExplosionY;
  int ExplosionDuraion;
} Sprite_Bullet_Definition;
extern Sprite_Bullet_Definition Sprite_Bullet;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int Start_X;
  int Start_Y;
  int End_X;
  int End_Y;
  int x;
  int y;
  int w;
  int h;
  int PosX;
  int PosY;
  int Direction;
  bool inUse;
} Platform_Definition;
extern Platform_Definition Platform;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int x;
  int y;
  int w;
  int h;
  int PosX;
  int PosY;
  bool inUse;
  int JumpVelocity;
} DropStone_Definition;
extern DropStone_Definition Sprite_DropStone[30];

// ##############################################
// ##############################################
// ##############################################
