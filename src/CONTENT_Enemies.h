#define NPC_LEFT 0
#define NPC_RIGHT 1
#define NPC_FRAME1 0
#define NPC_FRAME2 1
#define NPC_FRAME3 2
#define NPC_FRAME4 3
#define NPC_FRAME5 4
#define NPC_FRAME6 5
#define NPC_FRAME7 6
#define NPC_FRAME8 7

#define NPC_ALIVE 0
#define NPC_DEAD 1

#define NPC_TYPE_OWL 1   // -> does NOT stop at edges
#define NPC_TYPE_EYE 2   // -> does NOT stop at edges
#define NPC_TYPE_JELLY 3 // -> stops at edges
#define NPC_TYPE_CRAB 4  // -> stops at edges
#define NPC_TYPE_BEE 5   // -> flies
#define NPC_TYPE_BUG 6
#define NPC_TYPE_BALL 7
#define NPC_TYPE_HOOK1 8
#define NPC_TYPE_HOOK2 9
#define NPC_TYPE_HOOK3 10
#define NPC_TYPE_ROBINHOOD 11
#define NPC_TYPE_DRAGON 12
#define NPC_TYPE_SPIDER 13
#define NPC_TYPE_PIRANHA 14
#define NPC_TYPE_PIPE 15
#define NPC_TYPE_FIRECIRCLE 16 // NOT IN ORIGINAL GAME

void ENEMY_Change_Direction(int EnemyNumber);
void ENEMY_Check_Tilecollision(int EnemyNumber);
void ENEMIES_Define();
void ENEMY_Draw(int EnemyNumber);
void ENEMIES_Draw();
void ENEMY_Jump(int EnemyNumber);
void ENEMIES_Move();

// ##############################################
// ##############################################
// ##############################################

extern bool ENEMY_Collision_Down(int EnemyNumber);
extern bool ENEMY_Collision_Left(int EnemyNumber);
extern bool ENEMY_Collision_Right(int EnemyNumber);

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int FrameX[2][9][2];
  int FrameY[2][9][2];
  int FrameW[2][9][2];
  int FrameH[2][9][2];
  int JumpStrength;
  int RunStrength;
  bool Flying;
  bool Walker;
  int ColWidth;
  int ColHeight;
  int ColWidthHalf;
  int ColHeightHalf;
  bool FallOfCliffs;
  bool Stompable;
  bool Shootable;
  bool SpecialPath_Dragon;
  bool SpecialPath_Spider;
} Enemy_Type_Def;

extern Enemy_Type_Def Enemy_Type[30];

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int Frame;
  int Frame_7;
  int Frame_4;
} EnemyVariables;

extern EnemyVariables EV;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int PosX;
  int PosY;
  int Direction;
  int Type;
  bool Alive;
  bool Active;
  bool inUse;
  int StartPosX;
  int StartPosY;
  float JumpVelocity;
  float RunVelocity;
  bool OnGround;
  int MovementCounter;
} Enemy_Def;

extern Enemy_Def Enemy[MAX_NUM_ENEMIES];

// ##############################################
// ##############################################
// ##############################################
