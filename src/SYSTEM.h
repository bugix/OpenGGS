
// ##############################################
// ##############################################
// ##############################################

void defineAngles();
void OVERLAY_Volume_Draw_Music();
void OVERLAY_Volume_Draw_Sound();
void show_DebugInfos();
void toggleScreenmode();
void SYSTEM_SetResolution(int Resolution);
void Update_Screen();

// ##############################################
// ##############################################
// ##############################################

typedef struct Vector3_
{
  float x;
  float y;
  float z;
} Vector3;

  Vector3 vector_add(Vector3 *v, Vector3 *w);
  double vector_length(Vector3 *v);
  void vector_normalize(Vector3 *v);
  double vector_dot(Vector3 *v, Vector3 *w);
  Vector3 vector_cross(Vector3 *v, Vector3 *w);
  int vector_direction_32(Vector3 *v);

  extern double angle[32];

// ##############################################
// ##############################################
// ##############################################

void DrawChar(int left, int top, int colour, double charDegree, char letter);
void Print(int left, int top, int colour, double charDegree, const char *str);
void PrintInt(int left, int top, int colour, double charDegree, int number);

void DrawChar_Big(int left, int top, int colour, double charDegree, char letter);
void Print_Big(int left, int top, int colour, double charDegree, const char *str);
void PrintInt_Big(int left, int top, int colour, double charDegree, int number);

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int Resolution;
  int Volume_Music;
  int Volume_Sound;
} Config_Type;

extern Config_Type Config;

// ##############################################
// ##############################################
// ##############################################
