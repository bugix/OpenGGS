#include "globals.h"

//Uint8 *keys;

//Event handler
SDL_Event e;
const Uint8* currentKeyStates;

bool Key_UP;        int Key_UP_pressed_value;        bool Key_UP_pressed;
bool Key_RIGHT;     int Key_RIGHT_pressed_value;     bool Key_RIGHT_pressed;
bool Key_DOWN;      int Key_DOWN_pressed_value;      bool Key_DOWN_pressed;
bool Key_LEFT;      int Key_LEFT_pressed_value;      bool Key_LEFT_pressed;
bool Key_ESCAPE;    int Key_ESCAPE_pressed_value;    bool Key_ESCAPE_pressed;
bool Key_ENTER;     int Key_ENTER_pressed_value;     bool Key_ENTER_pressed;
bool Key_SPACE;     int Key_SPACE_pressed_value;     bool Key_SPACE_pressed;
bool Key_LSHIFT;    int Key_LSHIFT_pressed_value;    bool Key_LSHIFT_pressed;
bool Key_LALT;      int Key_LALT_pressed_value;      bool Key_LALT_pressed;
bool Key_TAB;       int Key_TAB_pressed_value;       bool Key_TAB_pressed;
bool Key_PAGEUP;    int Key_PAGEUP_pressed_value;    bool Key_PAGEUP_pressed;
bool Key_PAGEDOWN;  int Key_PAGEDOWN_pressed_value;  bool Key_PAGEDOWN_pressed;
bool Key_CTRL;      int Key_CTRL_pressed_value;      bool Key_CTRL_pressed;
bool Key_PLUS;      int Key_PLUS_pressed_value;      bool Key_PLUS_pressed;
bool Key_MINUS;     int Key_MINUS_pressed_value;     bool Key_MINUS_pressed;

bool Key_P;         int Key_P_pressed_value;         bool Key_P_pressed;
bool Key_S;         int Key_S_pressed_value;         bool Key_S_pressed;
bool Key_X;         int Key_X_pressed_value;         bool Key_X_pressed;
bool Key_Y;         int Key_Y_pressed_value;         bool Key_Y_pressed;
bool Key_1;         int Key_1_pressed_value;         bool Key_1_pressed;
bool Key_2;         int Key_2_pressed_value;         bool Key_2_pressed;
bool Key_3;         int Key_3_pressed_value;         bool Key_3_pressed;
bool Key_4;         int Key_4_pressed_value;         bool Key_4_pressed;
bool Key_5;         int Key_5_pressed_value;         bool Key_5_pressed;
bool Key_6;         int Key_6_pressed_value;         bool Key_6_pressed;
bool Key_7;         int Key_7_pressed_value;         bool Key_7_pressed;
bool Key_8;         int Key_8_pressed_value;         bool Key_8_pressed;
bool Key_9;         int Key_9_pressed_value;         bool Key_9_pressed;
bool Key_0;         int Key_0_pressed_value;         bool Key_0_pressed;
bool Button_0;      int Button_0_pressed_value;      bool Button_0_pressed;
bool Button_1;      int Button_1_pressed_value;      bool Button_1_pressed;
bool Button_2;      int Button_2_pressed_value;      bool Button_2_pressed;
bool Button_3;      int Button_3_pressed_value;      bool Button_3_pressed;
bool Button_4;      int Button_4_pressed_value;      bool Button_4_pressed;

bool Joy_UP;        int Joy_UP_pressed_value;        bool Joy_UP_pressed;
bool Joy_RIGHT;     int Joy_RIGHT_pressed_value;     bool Joy_RIGHT_pressed;
bool Joy_DOWN;      int Joy_DOWN_pressed_value;      bool Joy_DOWN_pressed;
bool Joy_LEFT;      int Joy_LEFT_pressed_value;      bool Joy_LEFT_pressed;
bool Joy_JUMP;      int Joy_JUMP_pressed_value;      bool Joy_JUMP_pressed;
bool Joy_ESCAPE;    int Joy_ESCAPE_pressed_value;    bool Joy_ESCAPE_pressed;
bool Joy_OK;        int Joy_OK_pressed_value;        bool Joy_OK_pressed;
bool Joy_SHOOT;     int Joy_SHOOT_pressed_value;     bool Joy_SHOOT_pressed;

bool Key_F1;        int Key_F1_pressed_value;        bool Key_F1_pressed;
bool Key_F2;        int Key_F2_pressed_value;        bool Key_F2_pressed;
bool Key_F3;        int Key_F3_pressed_value;        bool Key_F3_pressed;
bool Key_F4;        int Key_F4_pressed_value;        bool Key_F4_pressed;
bool Key_F5;        int Key_F5_pressed_value;        bool Key_F5_pressed;
bool Key_F6;        int Key_F6_pressed_value;        bool Key_F6_pressed;
bool Key_F7;        int Key_F7_pressed_value;        bool Key_F7_pressed;
bool Key_F8;        int Key_F8_pressed_value;        bool Key_F8_pressed;
bool Key_F9;        int Key_F9_pressed_value;        bool Key_F9_pressed;
bool Key_F10;       int Key_F10_pressed_value;       bool Key_F10_pressed;
bool Key_F11;       int Key_F11_pressed_value;       bool Key_F11_pressed;
bool Key_F12;       int Key_F12_pressed_value;       bool Key_F12_pressed;

int MouseX, MouseY;
bool MouseButtonLeft;  int MouseButtonLeft_pressed_value;   bool MouseButtonLeft_pressed;
bool MouseButtonMiddle;
bool MouseButtonRight; int MouseButtonRight_pressed_value; bool MouseButtonRight_pressed;

Joystick_Type Joystick;
Input_Type Unified;

// ##############################################
// ##############################################
// ##############################################

void getInput()
{



  currentKeyStates = SDL_GetKeyboardState( NULL );

  SDL_GetMouseState(&MouseX, &MouseY);  // writes Mouse-Position to MouseX and MouseY

  while( SDL_PollEvent( &e ) )
  {
    if (e.type == SDL_MOUSEBUTTONUP)
    {
      if(e.button.button == SDL_BUTTON_LEFT)  {MouseButtonLeft = false;}
      if(e.button.button == SDL_BUTTON_MIDDLE){MouseButtonMiddle = false;}
      if(e.button.button == SDL_BUTTON_RIGHT) {MouseButtonRight = false;}
    }

    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
      if(e.button.button == SDL_BUTTON_LEFT)  {MouseButtonLeft = true;}
      if(e.button.button == SDL_BUTTON_MIDDLE){MouseButtonMiddle = true;}
      if(e.button.button == SDL_BUTTON_RIGHT) {MouseButtonRight = true;}
    }



    switch( e.type )
    {

      case SDL_KEYDOWN:
      switch( e.key.keysym.sym )
      {
        case SDLK_ESCAPE: Key_ESCAPE = true; break;
        case SDLK_RETURN: Key_ENTER = true;  break;
        case SDLK_SPACE:  Key_SPACE = true;  break;
        case SDLK_LSHIFT: Key_LSHIFT = true; break;
        case SDLK_LALT:   Key_LALT = true;   break;
        case SDLK_TAB:    Key_TAB = true;    break;
        case SDLK_PAGEUP: Key_PAGEUP = true; break;
        case SDLK_PAGEDOWN: Key_PAGEDOWN = true; break;
        case SDLK_RCTRL:  Key_CTRL = true;   break;
        case SDLK_LCTRL:  Key_CTRL = true;   break;
        case SDLK_KP_PLUS:   Key_PLUS = true;   break;
        case SDLK_KP_MINUS:  Key_MINUS = true;  break;
        case SDLK_p:      Key_P = true;      break;
        case SDLK_s:      Key_S = true;      break;
        case SDLK_x:      Key_X = true;      break;
        case SDLK_y:      Key_Y = true;      break;
        case SDLK_F1:     Key_F1 = true;     break;
        case SDLK_F2:     Key_F2 = true;     break;
        case SDLK_F3:     Key_F3 = true;     break;
        case SDLK_F4:     Key_F4 = true;     break;
        case SDLK_F5:     Key_F5 = true;     break;
        case SDLK_F6:     Key_F6 = true;     break;
        case SDLK_F7:     Key_F7 = true;     break;
        case SDLK_F8:     Key_F8 = true;     break;
        case SDLK_F9:     Key_F9 = true;     break;
        case SDLK_F10:    Key_F10 = true;    break;
        case SDLK_F11:    Key_F11 = true;    break;
        case SDLK_F12:    Key_F12 = true;    break;
        case SDLK_UP:     Key_UP = true;     break;
        case SDLK_DOWN:   Key_DOWN = true;   break;
        case SDLK_LEFT:   Key_LEFT = true;   break;
        case SDLK_RIGHT:  Key_RIGHT = true;  break;
        default: break;
      }
      break;

      case SDL_KEYUP:
      switch( e.key.keysym.sym )
      {
        case SDLK_ESCAPE: Key_ESCAPE = false; break;
        case SDLK_RETURN: Key_ENTER = false;  break;
        case SDLK_SPACE:  Key_SPACE = false;  break;
        case SDLK_LSHIFT: Key_LSHIFT = false; break;
        case SDLK_LALT:   Key_LALT = false;   break;
        case SDLK_TAB:    Key_TAB = false;    break;
        case SDLK_PAGEUP: Key_PAGEUP = false; break;
        case SDLK_PAGEDOWN: Key_PAGEDOWN = false; break;
        case SDLK_RCTRL:  Key_CTRL = false;   break;
        case SDLK_LCTRL:  Key_CTRL = false;   break;
        case SDLK_KP_PLUS:   Key_PLUS = false;   break;
        case SDLK_KP_MINUS:  Key_MINUS = false;  break;
        case SDLK_p:      Key_P = false;      break;
        case SDLK_s:      Key_S = false;      break;
        case SDLK_x:      Key_X = false;      break;
        case SDLK_y:      Key_Y = false;      break;
        case SDLK_F1:     Key_F1 = false;     break;
        case SDLK_F2:     Key_F2 = false;     break;
        case SDLK_F3:     Key_F3 = false;     break;
        case SDLK_F4:     Key_F4 = false;     break;
        case SDLK_F5:     Key_F5 = false;     break;
        case SDLK_F6:     Key_F6 = false;     break;
        case SDLK_F7:     Key_F7 = false;     break;
        case SDLK_F8:     Key_F8 = false;     break;
        case SDLK_F9:     Key_F9 = false;     break;
        case SDLK_F10:    Key_F10 = false;    break;
        case SDLK_F11:    Key_F11 = false;    break;
        case SDLK_F12:    Key_F12 = false;    break;
        case SDLK_UP:     Key_UP = false;     break;
        case SDLK_DOWN:   Key_DOWN = false;   break;
        case SDLK_LEFT:   Key_LEFT = false;   break;
        case SDLK_RIGHT:  Key_RIGHT = false;  break;
        default: break;
      }
      break;

     default: break;
    }

    // INELEGANT SOLUTION
    if (e.type == SDL_JOYBUTTONDOWN)
    {
      if(e.jbutton.button == Joystick.UP)    {Joy_UP = true;}
      if(e.jbutton.button == Joystick.DOWN)  {Joy_DOWN = true;}
      if(e.jbutton.button == Joystick.LEFT)  {Joy_LEFT = true;}
      if(e.jbutton.button == Joystick.RIGHT) {Joy_RIGHT = true;}
      if(e.jbutton.button == Joystick.OK)    {Joy_OK = true;}
      if(e.jbutton.button == Joystick.Jump)  {Joy_JUMP = true;}
      if(e.jbutton.button == Joystick.ESCAPE){Joy_ESCAPE = true;} // XBOX-BUTTON
      if(e.jbutton.button == Joystick.Shoot) {Joy_SHOOT = true;}
    }
    if (e.type == SDL_JOYBUTTONUP)
    {
      if(e.jbutton.button == Joystick.UP)    {Joy_UP = false;}
      if(e.jbutton.button == Joystick.DOWN)  {Joy_DOWN = false;}
      if(e.jbutton.button == Joystick.LEFT)  {Joy_LEFT = false;}
      if(e.jbutton.button == Joystick.RIGHT) {Joy_RIGHT = false;}
      if(e.jbutton.button == Joystick.OK)    {Joy_OK = false;}
      if(e.jbutton.button == Joystick.Jump)  {Joy_JUMP = false;}
      if(e.jbutton.button == Joystick.ESCAPE){Joy_ESCAPE = false;} // XBOX-BUTTON
      if(e.jbutton.button == Joystick.Shoot) {Joy_SHOOT = false;}
    }


  }

  if (!Key_ESCAPE){Key_ESCAPE_pressed_value = 0; Key_ESCAPE_pressed = false;} else
                  {if (Key_ESCAPE_pressed_value == 2){Key_ESCAPE_pressed_value = 1; Key_ESCAPE_pressed = false;}
                   if (Key_ESCAPE_pressed_value == 0){Key_ESCAPE_pressed_value = 2; Key_ESCAPE_pressed = true;}}
  if (!Key_ENTER) {Key_ENTER_pressed_value = 0; Key_ENTER_pressed = false;} else
                  {if (Key_ENTER_pressed_value == 2){Key_ENTER_pressed_value = 1; Key_ENTER_pressed = false;}
                   if (Key_ENTER_pressed_value == 0){Key_ENTER_pressed_value = 2; Key_ENTER_pressed = true;}}
  if (!Key_SPACE) {Key_SPACE_pressed_value = 0; Key_SPACE_pressed = false;} else
                  {if (Key_SPACE_pressed_value == 2){Key_SPACE_pressed_value = 1; Key_SPACE_pressed = false;}
                   if (Key_SPACE_pressed_value == 0){Key_SPACE_pressed_value = 2; Key_SPACE_pressed = true;}}
  if (!Key_LSHIFT){Key_LSHIFT_pressed_value = 0; Key_LSHIFT_pressed = false;} else
                  {if (Key_LSHIFT_pressed_value == 2){Key_LSHIFT_pressed_value = 1; Key_LSHIFT_pressed = false;}
                   if (Key_LSHIFT_pressed_value == 0){Key_LSHIFT_pressed_value = 2; Key_LSHIFT_pressed = true;}}
  if (!Key_LALT){Key_LALT_pressed_value = 0; Key_LALT_pressed = false;} else
                  {if (Key_LALT_pressed_value == 2){Key_LALT_pressed_value = 1; Key_LALT_pressed = false;}
                   if (Key_LALT_pressed_value == 0){Key_LALT_pressed_value = 2; Key_LALT_pressed = true;}}
  if (!Key_TAB){Key_TAB_pressed_value = 0; Key_TAB_pressed = false;} else
                  {if (Key_TAB_pressed_value == 2){Key_TAB_pressed_value = 1; Key_TAB_pressed = false;}
                   if (Key_TAB_pressed_value == 0){Key_TAB_pressed_value = 2; Key_TAB_pressed = true;}}
  if (!Key_PAGEUP){Key_PAGEUP_pressed_value = 0; Key_PAGEUP_pressed = false;} else
                  {if (Key_PAGEUP_pressed_value == 2){Key_PAGEUP_pressed_value = 1; Key_PAGEUP_pressed = false;}
                   if (Key_PAGEUP_pressed_value == 0){Key_PAGEUP_pressed_value = 2; Key_PAGEUP_pressed = true;}}
  if (!Key_PAGEDOWN){Key_PAGEDOWN_pressed_value = 0; Key_PAGEDOWN_pressed = false;} else
                  {if (Key_PAGEDOWN_pressed_value == 2){Key_PAGEDOWN_pressed_value = 1; Key_PAGEDOWN_pressed = false;}
                   if (Key_PAGEDOWN_pressed_value == 0){Key_PAGEDOWN_pressed_value = 2; Key_PAGEDOWN_pressed = true;}}
  if (!Key_CTRL){Key_CTRL_pressed_value = 0; Key_CTRL_pressed = false;} else
                  {if (Key_CTRL_pressed_value == 2){Key_CTRL_pressed_value = 1; Key_CTRL_pressed = false;}
                   if (Key_CTRL_pressed_value == 0){Key_CTRL_pressed_value = 2; Key_CTRL_pressed = true;}}
  if (!Key_PLUS){Key_PLUS_pressed_value = 0; Key_PLUS_pressed = false;} else
                  {if (Key_PLUS_pressed_value == 2){Key_PLUS_pressed_value = 1; Key_PLUS_pressed = false;}
                   if (Key_PLUS_pressed_value == 0){Key_PLUS_pressed_value = 2; Key_PLUS_pressed = true;}}
  if (!Key_MINUS){Key_MINUS_pressed_value = 0; Key_MINUS_pressed = false;} else
                  {if (Key_MINUS_pressed_value == 2){Key_MINUS_pressed_value = 1; Key_MINUS_pressed = false;}
                   if (Key_MINUS_pressed_value == 0){Key_MINUS_pressed_value = 2; Key_MINUS_pressed = true;}}
  if (!Key_P)     {Key_P_pressed_value = 0; Key_P_pressed = false;} else
                  {if (Key_P_pressed_value == 2){Key_P_pressed_value = 1; Key_P_pressed = false;}
                   if (Key_P_pressed_value == 0){Key_P_pressed_value = 2; Key_P_pressed = true;}}
  if (!Key_S)     {Key_S_pressed_value = 0; Key_S_pressed = false;} else
                  {if (Key_S_pressed_value == 2){Key_S_pressed_value = 1; Key_S_pressed = false;}
                   if (Key_S_pressed_value == 0){Key_S_pressed_value = 2; Key_S_pressed = true;}}
  if (!Key_X)     {Key_X_pressed_value = 0; Key_X_pressed = false;} else
                  {if (Key_X_pressed_value == 2){Key_X_pressed_value = 1; Key_X_pressed = false;}
                   if (Key_X_pressed_value == 0){Key_X_pressed_value = 2; Key_X_pressed = true;}}
  if (!Key_Y)     {Key_Y_pressed_value = 0; Key_Y_pressed = false;} else
                  {if (Key_Y_pressed_value == 2){Key_Y_pressed_value = 1; Key_Y_pressed = false;}
                   if (Key_Y_pressed_value == 0){Key_Y_pressed_value = 2; Key_Y_pressed = true;}}
  if (!Key_F1)    {Key_F1_pressed_value = 0; Key_F1_pressed = false;} else
                  {if (Key_F1_pressed_value == 2){Key_F1_pressed_value = 1; Key_F1_pressed = false;}
                   if (Key_F1_pressed_value == 0){Key_F1_pressed_value = 2; Key_F1_pressed = true;}}
  if (!Key_F2)    {Key_F2_pressed_value = 0; Key_F2_pressed = false;} else
                  {if (Key_F2_pressed_value == 2){Key_F2_pressed_value = 1; Key_F2_pressed = false;}
                   if (Key_F2_pressed_value == 0){Key_F2_pressed_value = 2; Key_F2_pressed = true;}}
  if (!Key_F3)    {Key_F3_pressed_value = 0; Key_F3_pressed = false;} else
                  {if (Key_F3_pressed_value == 2){Key_F3_pressed_value = 1; Key_F3_pressed = false;}
                   if (Key_F3_pressed_value == 0){Key_F3_pressed_value = 2; Key_F3_pressed = true;}}
  if (!Key_F4)    {Key_F4_pressed_value = 0; Key_F4_pressed = false;} else
                  {if (Key_F4_pressed_value == 2){Key_F4_pressed_value = 1; Key_F4_pressed = false;}
                   if (Key_F4_pressed_value == 0){Key_F4_pressed_value = 2; Key_F4_pressed = true;}}
  if (!Key_F5)    {Key_F5_pressed_value = 0; Key_F5_pressed = false;} else
                  {if (Key_F5_pressed_value == 2){Key_F5_pressed_value = 1; Key_F5_pressed = false;}
                   if (Key_F5_pressed_value == 0){Key_F5_pressed_value = 2; Key_F5_pressed = true;}}
  if (!Key_F6)    {Key_F6_pressed_value = 0; Key_F6_pressed = false;} else
                  {if (Key_F6_pressed_value == 2){Key_F6_pressed_value = 1; Key_F6_pressed = false;}
                   if (Key_F6_pressed_value == 0){Key_F6_pressed_value = 2; Key_F6_pressed = true;}}
  if (!Key_F7)    {Key_F7_pressed_value = 0; Key_F7_pressed = false;} else
                  {if (Key_F7_pressed_value == 2){Key_F7_pressed_value = 1; Key_F7_pressed = false;}
                   if (Key_F7_pressed_value == 0){Key_F7_pressed_value = 2; Key_F7_pressed = true;}}
  if (!Key_F8)    {Key_F8_pressed_value = 0; Key_F8_pressed = false;} else
                  {if (Key_F8_pressed_value == 2){Key_F8_pressed_value = 1; Key_F8_pressed = false;}
                   if (Key_F8_pressed_value == 0){Key_F8_pressed_value = 2; Key_F8_pressed = true;}}
  if (!Key_F9)    {Key_F9_pressed_value = 0; Key_F9_pressed = false;} else
                  {if (Key_F9_pressed_value == 2){Key_F9_pressed_value = 1; Key_F9_pressed = false;}
                   if (Key_F9_pressed_value == 0){Key_F9_pressed_value = 2; Key_F9_pressed = true;}}
  if (!Key_F10)   {Key_F10_pressed_value = 0; Key_F10_pressed = false;} else
                  {if (Key_F10_pressed_value == 2){Key_F10_pressed_value = 1; Key_F10_pressed = false;}
                   if (Key_F10_pressed_value == 0){Key_F10_pressed_value = 2; Key_F10_pressed = true;}}
  if (!Key_F11)   {Key_F11_pressed_value = 0; Key_F11_pressed = false;} else
                  {if (Key_F11_pressed_value == 2){Key_F11_pressed_value = 1; Key_F11_pressed = false;}
                   if (Key_F11_pressed_value == 0){Key_F11_pressed_value = 2; Key_F11_pressed = true;}}
  if (!Key_F12)   {Key_F12_pressed_value = 0; Key_F12_pressed = false;} else
                  {if (Key_F12_pressed_value == 2){Key_F12_pressed_value = 1; Key_F12_pressed = false;}
                   if (Key_F12_pressed_value == 0){Key_F12_pressed_value = 2; Key_F12_pressed = true;}}
  if (!Key_UP)    {Key_UP_pressed_value = 0; Key_UP_pressed = false;} else
                  {if (Key_UP_pressed_value == 2){Key_UP_pressed_value = 1; Key_UP_pressed = false;}
                   if (Key_UP_pressed_value == 0){Key_UP_pressed_value = 2; Key_UP_pressed = true;}}
  if (!Key_LEFT)  {Key_LEFT_pressed_value = 0; Key_LEFT_pressed = false;} else
                  {if (Key_LEFT_pressed_value == 2){Key_LEFT_pressed_value = 1; Key_LEFT_pressed = false;}
                   if (Key_LEFT_pressed_value == 0){Key_LEFT_pressed_value = 2; Key_LEFT_pressed = true;}}
  if (!Key_DOWN)  {Key_DOWN_pressed_value = 0; Key_DOWN_pressed = false;} else
                  {if (Key_DOWN_pressed_value == 2){Key_DOWN_pressed_value = 1; Key_DOWN_pressed = false;}
                   if (Key_DOWN_pressed_value == 0){Key_DOWN_pressed_value = 2; Key_DOWN_pressed = true;}}
  if (!Key_RIGHT) {Key_RIGHT_pressed_value = 0; Key_RIGHT_pressed = false;} else
                  {if (Key_RIGHT_pressed_value == 2){Key_RIGHT_pressed_value = 1; Key_RIGHT_pressed = false;}
                   if (Key_RIGHT_pressed_value == 0){Key_RIGHT_pressed_value = 2; Key_RIGHT_pressed = true;}}


  if (!Joy_UP)    {Joy_UP_pressed_value = 0; Joy_UP_pressed = false;} else
                  {if (Joy_UP_pressed_value == 2){Joy_UP_pressed_value = 1; Joy_UP_pressed = false;}
                   if (Joy_UP_pressed_value == 0){Joy_UP_pressed_value = 2; Joy_UP_pressed = true;}}
  if (!Joy_LEFT)  {Joy_LEFT_pressed_value = 0; Joy_LEFT_pressed = false;} else
                  {if (Joy_LEFT_pressed_value == 2){Joy_LEFT_pressed_value = 1; Joy_LEFT_pressed = false;}
                   if (Joy_LEFT_pressed_value == 0){Joy_LEFT_pressed_value = 2; Joy_LEFT_pressed = true;}}
  if (!Joy_DOWN)  {Joy_DOWN_pressed_value = 0; Joy_DOWN_pressed = false;} else
                  {if (Joy_DOWN_pressed_value == 2){Joy_DOWN_pressed_value = 1; Joy_DOWN_pressed = false;}
                   if (Joy_DOWN_pressed_value == 0){Joy_DOWN_pressed_value = 2; Joy_DOWN_pressed = true;}}
  if (!Joy_RIGHT) {Joy_RIGHT_pressed_value = 0; Joy_RIGHT_pressed = false;} else
                  {if (Joy_RIGHT_pressed_value == 2){Joy_RIGHT_pressed_value = 1; Joy_RIGHT_pressed = false;}
                   if (Joy_RIGHT_pressed_value == 0){Joy_RIGHT_pressed_value = 2; Joy_RIGHT_pressed = true;}}
  if (!Joy_JUMP)  {Joy_JUMP_pressed_value = 0; Joy_JUMP_pressed = false;} else
                  {if (Joy_JUMP_pressed_value == 2){Joy_JUMP_pressed_value = 1; Joy_JUMP_pressed = false;}
                   if (Joy_JUMP_pressed_value == 0){Joy_JUMP_pressed_value = 2; Joy_JUMP_pressed = true;}}
  if (!Joy_OK)  {Joy_OK_pressed_value = 0; Joy_OK_pressed = false;} else
                  {if (Joy_OK_pressed_value == 2){Joy_OK_pressed_value = 1; Joy_OK_pressed = false;}
                   if (Joy_OK_pressed_value == 0){Joy_OK_pressed_value = 2; Joy_OK_pressed = true;}}
  if (!Joy_ESCAPE) {Joy_ESCAPE_pressed_value = 0; Joy_ESCAPE_pressed = false;} else
                  {if (Joy_ESCAPE_pressed_value == 2){Joy_ESCAPE_pressed_value = 1; Joy_ESCAPE_pressed = false;}
                   if (Joy_ESCAPE_pressed_value == 0){Joy_ESCAPE_pressed_value = 2; Joy_ESCAPE_pressed = true;}}
  if (!Joy_SHOOT) {Joy_SHOOT_pressed_value = 0; Joy_SHOOT_pressed = false;} else
                  {if (Joy_SHOOT_pressed_value == 2){Joy_SHOOT_pressed_value = 1; Joy_SHOOT_pressed = false;}
                   if (Joy_SHOOT_pressed_value == 0){Joy_SHOOT_pressed_value = 2; Joy_SHOOT_pressed = true;}}

  if (!MouseButtonLeft) {MouseButtonLeft_pressed_value = 0; MouseButtonLeft_pressed = false;} else
                  {if (MouseButtonLeft_pressed_value == 2){MouseButtonLeft_pressed_value = 1; MouseButtonLeft_pressed = false;}
                   if (MouseButtonLeft_pressed_value == 0){MouseButtonLeft_pressed_value = 2; MouseButtonLeft_pressed = true;}}

  if (!MouseButtonRight) {MouseButtonRight_pressed_value = 0; MouseButtonRight_pressed = false;} else
                  {if (MouseButtonRight_pressed_value == 2){MouseButtonRight_pressed_value = 1; MouseButtonRight_pressed = false;}
                   if (MouseButtonRight_pressed_value == 0){MouseButtonRight_pressed_value = 2; MouseButtonRight_pressed = true;}}
}

// ##############################################
// ##############################################
// ##############################################
