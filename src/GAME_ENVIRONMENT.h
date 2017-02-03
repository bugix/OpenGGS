
#define WORLDWIDTH 50
#define WORLDHEIGHT 50

#define TYPE_C64 10
#define TYPE_OPENGGS 20
#define TYPE_AMIGA 30

#define RESOLUTION_640x480 10
#define RESOLUTION_800x600 20
#define RESOLUTION_1280x720 30



// ##############################################
// ##############################################
// ##############################################

void GAME_ENVIRONMENT_Define();
void GAMETYPE_Load();
void Options_Save();
void Options_Load();
void Option_GameType_Load();

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int Gravity;           //
  int TerminalVelocity;  // MAXIMUM FALLING SPEED
  float Friction;        //
  int WallFriction;      // TERMINAL VELOCITY WHEN "GRINDING" DOWN A WALL
  int TileSwitchSpeed;
} World_Type;

extern World_Type World;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  char Stage[20][128];
  char StageShort[20][128];
  char Tiles[128];
  char Player[128];
  char PlayerDefinition[128];
  char Enemies[128];
  char EnemiesDefinition[128];
  char PowerUp[128];
  char PowerUpDefinition[128];
  char Interface[128];
  char Font[128];
  char WavChunk[20][128];
  char BGM_Title[128];
  char BGM_Outdoors[128];
  char BGM_Indoors[128];
} Def_FileNames;

extern Def_FileNames FileName; // FILENAME BUFFERS

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int Mode;
  int Screen_Width;
  int Screen_Height;
  int ScreenWidthTiles;
  int ScreenHeightTiles;
  int Resolution;
  bool ShowDebugInfos_Tiles;
  int GameType;
  int VolumeSounds;
  int VolumeMusic;
  int TempMusicVolume;
  int TempMusicOffCounter;
  bool MusicEnabled;
  bool DirDefaultExists;
  bool DirC64Exists;
  bool DirAmigaExists;
  bool SplashscreensEnabled;
  bool PixelPerfectRunning;
  int RefreshMS;
  int FPS_Counter;
  bool RandomLevels;
} GameVariables_Type;

extern GameVariables_Type GV;

// ##############################################
// ##############################################
// ##############################################

extern int CurrentScreenMode;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int Screen_Width;
  int Screen_Height;
  int VolumeSounds;
  int VolumeMusic;
  int GameType;
  int Var4;
  int Var5;
  int Var6;
} SavedOptions_Type;

extern SavedOptions_Type SavedOptions;

// ##############################################
// ##############################################
// ##############################################
