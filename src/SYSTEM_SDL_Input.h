
// ##############################################
// ##############################################
// ##############################################

void getInput();
void INPUT_General();

// ##############################################
// ##############################################
// ##############################################

//Event handler
extern SDL_Event e;
extern const Uint8* currentKeyStates;

extern bool Key_ESCAPE;    extern bool Key_ESCAPE_pressed;
extern bool Key_ENTER;     extern bool Key_ENTER_pressed;
extern bool Key_SPACE;     extern bool Key_SPACE_pressed;
extern bool Key_LSHIFT;    extern bool Key_LSHIFT_pressed;
extern bool Key_LALT;      extern bool Key_LALT_pressed;
extern bool Key_TAB;       extern bool Key_TAB_pressed;
extern bool Key_PAGEUP;    extern bool Key_PAGEUP_pressed;
extern bool Key_PAGEDOWN;  extern bool Key_PAGEDOWN_pressed;
extern bool Key_CTRL;      extern bool Key_CTRL_pressed;

extern bool Key_UP;        extern bool Key_UP_pressed;
extern bool Key_RIGHT;     extern bool Key_RIGHT_pressed;
extern bool Key_DOWN;      extern bool Key_DOWN_pressed;
extern bool Key_LEFT;      extern bool Key_LEFT_pressed;

extern bool Key_PLUS;      extern bool Key_PLUS_pressed;
extern bool Key_MINUS;     extern bool Key_MINUS_pressed;

extern bool Key_P;         extern bool Key_P_pressed;
extern bool Key_S;         extern bool Key_S_pressed;
extern bool Key_X;         extern bool Key_X_pressed;
extern bool Key_Y;         extern bool Key_Y_pressed;

extern bool Key_1;         extern bool Key_1_pressed;
extern bool Key_2;         extern bool Key_2_pressed;
extern bool Key_3;         extern bool Key_3_pressed;
extern bool Key_4;         extern bool Key_4_pressed;
extern bool Key_5;         extern bool Key_5_pressed;
extern bool Key_6;         extern bool Key_6_pressed;
extern bool Key_7;         extern bool Key_7_pressed;
extern bool Key_8;         extern bool Key_8_pressed;
extern bool Key_9;         extern bool Key_9_pressed;
extern bool Key_0;         extern bool Key_0_pressed;

extern bool Key_F1;        extern bool Key_F1_pressed;
extern bool Key_F2;        extern bool Key_F2_pressed;
extern bool Key_F3;        extern bool Key_F3_pressed;
extern bool Key_F4;        extern bool Key_F4_pressed;
extern bool Key_F5;        extern bool Key_F5_pressed;
extern bool Key_F6;        extern bool Key_F6_pressed;
extern bool Key_F7;        extern bool Key_F7_pressed;
extern bool Key_F8;        extern bool Key_F8_pressed;
extern bool Key_F9;        extern bool Key_F9_pressed;
extern bool Key_F10;       extern bool Key_F10_pressed;
extern bool Key_F11;       extern bool Key_F11_pressed;
extern bool Key_F12;       extern bool Key_F12_pressed;

extern bool Button_0;      extern bool Button_0_pressed;
extern bool Button_1;      extern bool Button_1_pressed;
extern bool Button_2;      extern bool Button_2_pressed;
extern bool Button_3;      extern bool Button_3_pressed;
extern bool Button_4;      extern bool Button_4_pressed;

extern bool Joy_UP;        extern bool Joy_UP_pressed;
extern bool Joy_RIGHT;     extern bool Joy_RIGHT_pressed;
extern bool Joy_DOWN;      extern bool Joy_DOWN_pressed;
extern bool Joy_LEFT;      extern bool Joy_LEFT_pressed;
extern bool Joy_JUMP;      extern bool Joy_JUMP_pressed;
extern bool Joy_ESCAPE;    extern bool Joy_ESCAPE_pressed;
extern bool Joy_OK;        extern bool Joy_OK_pressed;
extern bool Joy_SHOOT;     extern bool Joy_SHOOT_pressed;

extern int MouseX;
extern int MouseY;
extern bool MouseButtonLeft;   extern bool MouseButtonLeft_pressed;
extern bool MouseButtonMiddle;
extern bool MouseButtonRight;  extern bool MouseButtonRight_pressed;

extern SDL_Joystick* GameController;
// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int UP;
  int RIGHT;
  int DOWN;
  int LEFT;
  int Jump;
  int ESCAPE;
  int OK;
  int Shoot;
} Joystick_Type;

extern Joystick_Type Joystick;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  bool Jump;
} Input_Type;

extern Input_Type Unified;

