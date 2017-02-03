
#define INTERFACE_MARK_SOLID 40
#define INTERFACE_MARK_EXIT 41
#define INTERFACE_MARK_LETHAL 42
#define INTERFACE_MARK_FIRE 43
#define INTERFACE_MARK_COIN 44
#define INTERFACE_MARK_COIN_BLOCK 45
#define INTERFACE_MARK_BREAKABLE 46
#define INTERFACE_MARK_POWERUP_BLOCK 47
#define INTERFACE_MARK_COLOUR_CHANGING 48
#define INTERFACE_MARK_DROPSTONE 49
#define INTERFACE_MARK_WARPSTONE 50
#define INTERFACE_MARK_MODULE_END 160

#define INTERFACE_MARK_GRAB 1
#define INTERFACE_MARK_GRAB_ACTIVE 2
#define INTERFACE_MARK_DELETE 3
#define INTERFACE_MARK_ARROW_UP 4
#define INTERFACE_MARK_ARROW_DOWN 5

#define INTERFACE_MARK_CHECKPOINT 80
#define INTERFACE_MARK_CHECKPOINT_ACTIVE 81

void INTERFACE_Tile_Draw(int x, int y, int Number);

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int x[20];
  int y[20];
  int MenuEntries;
  int Active;
  int MenuEntriesMainMenu;
  int ActiveMainMenu;
  int MenuEntriesOptions;
  int ActiveOptions;
  int MenuEntriesFileLoad;
  int ActiveFileLoad;
  int Cols;
} Menu_Def;
extern Menu_Def Menu;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int PlayerX;
  int PlayerY;
  int BonusX;
  int BonusY;
  int LivesX;
  int LivesY;
  int StageX;
  int StageY;
  int TimeX;
  int TimeY;
  int SmallCoinX;
  int SmallCoinY;
} HUD_Def;
extern HUD_Def HUD;
