#include "globals.h"

SDL_Rect TextDstRect;
SDL_Rect TextSrcRect;
int TextIndex;

// ##############################################
// ##############################################
// ##############################################

void PrintInt(int left, int top, int colour, double charDegree, int number)
{
  char Integer[] = "012345678901234567890123456789";
  // itoa(number,Integer,10);  // NOT GP2X compatible
  sprintf (Integer, "%d", number);  // GP2X compatible
  Print(left, top, colour, charDegree, Integer);
}

// ##############################################
// ##############################################
// ##############################################

void Print(int left, int top, int colour, double charDegree, const char *str)
{
  int pos = 0;
  while (*str)
  {
    DrawChar(left + pos, top, colour, charDegree, *str++);
    pos += 10;
  }
}

// ##############################################
// ##############################################
// ##############################################

void PrintInt_Big(int left, int top, int colour, double charDegree, int number)
{
  char Integer[] = "012345678901234567890123456789";
  // itoa(number,Integer,10);  // NOT GP2X compatible
  sprintf (Integer, "%d", number);  // GP2X compatible
  Print_Big(left, top, colour, charDegree, Integer);
}

// ##############################################
// ##############################################
// ##############################################

void Print_Big(int left, int top, int colour, double charDegree, const char *str)
{
  int pos = 0;
  while (*str)
  {
    DrawChar_Big(left + pos, top, colour, charDegree, *str++);
    pos += 16;
  }
}

// ##############################################
// ##############################################
// ##############################################

void DrawChar(int left, int top, int colour, double charDegree, char letter)
{
  TextSrcRect.x = 0;      TextSrcRect.y = 0;
  TextDstRect.x = left;   TextDstRect.y = top;
  TextSrcRect.w = 10;      TextSrcRect.h = 10;
  TextDstRect.w = 10;      TextDstRect.h = 10;

  if(letter == 'a' || letter == 'A'){TextSrcRect.x = 0;   TextSrcRect.y = 0;}
  if(letter == 'b' || letter == 'B'){TextSrcRect.x = 10;  TextSrcRect.y = 0;}
  if(letter == 'c' || letter == 'C'){TextSrcRect.x = 20;  TextSrcRect.y = 0;}
  if(letter == 'd' || letter == 'D'){TextSrcRect.x = 30;  TextSrcRect.y = 0;}
  if(letter == 'e' || letter == 'E'){TextSrcRect.x = 40;  TextSrcRect.y = 0;}
  if(letter == 'f' || letter == 'F'){TextSrcRect.x = 50;  TextSrcRect.y = 0;}
  if(letter == 'g' || letter == 'G'){TextSrcRect.x = 60;  TextSrcRect.y = 0;}
  if(letter == 'h' || letter == 'H'){TextSrcRect.x = 70;  TextSrcRect.y = 0;}
  if(letter == 'i' || letter == 'I'){TextSrcRect.x = 80;  TextSrcRect.y = 0;}
  if(letter == 'j' || letter == 'J'){TextSrcRect.x = 90;  TextSrcRect.y = 0;}
  if(letter == 'k' || letter == 'K'){TextSrcRect.x = 100; TextSrcRect.y = 0;}
  if(letter == 'l' || letter == 'L'){TextSrcRect.x = 110; TextSrcRect.y = 0;}
  if(letter == 'm' || letter == 'M'){TextSrcRect.x = 120; TextSrcRect.y = 0;}
  if(letter == 'n' || letter == 'N'){TextSrcRect.x = 130; TextSrcRect.y = 0;}
  if(letter == 'o' || letter == 'O'){TextSrcRect.x = 140; TextSrcRect.y = 0;}
  if(letter == 'p' || letter == 'P'){TextSrcRect.x = 150; TextSrcRect.y = 0;}
  if(letter == 'q' || letter == 'Q'){TextSrcRect.x = 160; TextSrcRect.y = 0;}
  if(letter == 'r' || letter == 'R'){TextSrcRect.x = 170; TextSrcRect.y = 0;}
  if(letter == 's' || letter == 'S'){TextSrcRect.x = 180; TextSrcRect.y = 0;}
  if(letter == 't' || letter == 'T'){TextSrcRect.x = 190; TextSrcRect.y = 0;}
  if(letter == 'u' || letter == 'U'){TextSrcRect.x = 200; TextSrcRect.y = 0;}
  if(letter == 'v' || letter == 'V'){TextSrcRect.x = 210; TextSrcRect.y = 0;}
  if(letter == 'w' || letter == 'W'){TextSrcRect.x = 220; TextSrcRect.y = 0;}
  if(letter == 'x' || letter == 'X'){TextSrcRect.x = 230; TextSrcRect.y = 0;}
  if(letter == 'y' || letter == 'Y'){TextSrcRect.x = 240; TextSrcRect.y = 0;}
  if(letter == 'z' || letter == 'Z'){TextSrcRect.x = 250; TextSrcRect.y = 0;}

  if(letter == 'a'){TextSrcRect.x = 0;   TextSrcRect.y = 10;}
  if(letter == 'b'){TextSrcRect.x = 10;  TextSrcRect.y = 10;}
  if(letter == 'c'){TextSrcRect.x = 20;  TextSrcRect.y = 10;}
  if(letter == 'd'){TextSrcRect.x = 30;  TextSrcRect.y = 10;}
  if(letter == 'e'){TextSrcRect.x = 40;  TextSrcRect.y = 10;}
  if(letter == 'f'){TextSrcRect.x = 50;  TextSrcRect.y = 10;}
  if(letter == 'g'){TextSrcRect.x = 60;  TextSrcRect.y = 10;}
  if(letter == 'h'){TextSrcRect.x = 70;  TextSrcRect.y = 10;}
  if(letter == 'i'){TextSrcRect.x = 80;  TextSrcRect.y = 10;}
  if(letter == 'j'){TextSrcRect.x = 90;  TextSrcRect.y = 10;}
  if(letter == 'k'){TextSrcRect.x = 100; TextSrcRect.y = 10;}
  if(letter == 'l'){TextSrcRect.x = 110; TextSrcRect.y = 10;}
  if(letter == 'm'){TextSrcRect.x = 120; TextSrcRect.y = 10;}
  if(letter == 'n'){TextSrcRect.x = 130; TextSrcRect.y = 10;}
  if(letter == 'o'){TextSrcRect.x = 140; TextSrcRect.y = 10;}
  if(letter == 'p'){TextSrcRect.x = 150; TextSrcRect.y = 10;}
  if(letter == 'q'){TextSrcRect.x = 160; TextSrcRect.y = 10;}
  if(letter == 'r'){TextSrcRect.x = 170; TextSrcRect.y = 10;}
  if(letter == 's'){TextSrcRect.x = 180; TextSrcRect.y = 10;}
  if(letter == 't'){TextSrcRect.x = 190; TextSrcRect.y = 10;}
  if(letter == 'u'){TextSrcRect.x = 200; TextSrcRect.y = 10;}
  if(letter == 'v'){TextSrcRect.x = 210; TextSrcRect.y = 10;}
  if(letter == 'w'){TextSrcRect.x = 220; TextSrcRect.y = 10;}
  if(letter == 'x'){TextSrcRect.x = 230; TextSrcRect.y = 10;}
  if(letter == 'y'){TextSrcRect.x = 240; TextSrcRect.y = 10;}
  if(letter == 'z'){TextSrcRect.x = 250; TextSrcRect.y = 10;}

  if(letter == ' '){TextSrcRect.x = 0;   TextSrcRect.y = 20;}
  if(letter == '0'){TextSrcRect.x = 10;  TextSrcRect.y = 20;}
  if(letter == '1'){TextSrcRect.x = 20;  TextSrcRect.y = 20;}
  if(letter == '2'){TextSrcRect.x = 30;  TextSrcRect.y = 20;}
  if(letter == '3'){TextSrcRect.x = 40;  TextSrcRect.y = 20;}
  if(letter == '4'){TextSrcRect.x = 50;  TextSrcRect.y = 20;}
  if(letter == '5'){TextSrcRect.x = 60;  TextSrcRect.y = 20;}
  if(letter == '6'){TextSrcRect.x = 70;  TextSrcRect.y = 20;}
  if(letter == '7'){TextSrcRect.x = 80;  TextSrcRect.y = 20;}
  if(letter == '8'){TextSrcRect.x = 90;  TextSrcRect.y = 20;}
  if(letter == '9'){TextSrcRect.x = 100; TextSrcRect.y = 20;}

  if(letter == 'Ä'){TextSrcRect.x = 110; TextSrcRect.y = 20;}
  if(letter == 'Ö'){TextSrcRect.x = 120; TextSrcRect.y = 20;}
  if(letter == 'Ü'){TextSrcRect.x = 130; TextSrcRect.y = 20;}
  if(letter == 'ä'){TextSrcRect.x = 140; TextSrcRect.y = 20;}
  if(letter == 'ö'){TextSrcRect.x = 150; TextSrcRect.y = 20;}
  if(letter == 'ü'){TextSrcRect.x = 160; TextSrcRect.y = 20;}

  if(letter == '.'){TextSrcRect.x = 0;   TextSrcRect.y = 30;}
  if(letter == ','){TextSrcRect.x = 10;  TextSrcRect.y = 30;}
  if(letter == '?'){TextSrcRect.x = 20;  TextSrcRect.y = 30;}
  if(letter == '!'){TextSrcRect.x = 30;  TextSrcRect.y = 30;}
  if(letter == '\''){TextSrcRect.x = 40;  TextSrcRect.y = 30;}
  if(letter == '-'){TextSrcRect.x = 50;  TextSrcRect.y = 30;}
  if(letter == '+'){TextSrcRect.x = 60;  TextSrcRect.y = 30;}
  if(letter == '*'){TextSrcRect.x = 70;  TextSrcRect.y = 30;}
  if(letter == '/'){TextSrcRect.x = 80;  TextSrcRect.y = 30;}
  if(letter == '"'){TextSrcRect.x = 90;  TextSrcRect.y = 30;}
  if(letter == '('){TextSrcRect.x = 100; TextSrcRect.y = 30;}
  if(letter == ')'){TextSrcRect.x = 110; TextSrcRect.y = 30;}
  if(letter == '='){TextSrcRect.x = 120; TextSrcRect.y = 30;}
  if(letter == ':'){TextSrcRect.x = 130; TextSrcRect.y = 30;}

  if(letter == '<'){TextSrcRect.x = 140; TextSrcRect.y = 30;} // UNCHECKED BOX
  if(letter == '>'){TextSrcRect.x = 150; TextSrcRect.y = 30;} // CHECKED BOX

  if(colour<4){TextSrcRect.y += colour*40;}

  SDL_RenderCopyEx( gRenderer, fontTexture, &TextSrcRect, &TextDstRect, charDegree, NULL, SDL_FLIP_NONE );
  letter = ' ';
}

// ##############################################
// ##############################################
// ##############################################

// ##############################################
// ##############################################
// ##############################################

void DrawChar_Big(int left, int top, int colour, double charDegree, char letter)
{
  TextSrcRect.x = 0;      TextSrcRect.y = 0;
  TextDstRect.x = left;   TextDstRect.y = top;
  TextSrcRect.w = 16;      TextSrcRect.h = 16;
  TextDstRect.w = 16;      TextDstRect.h = 16;

  if(letter == 'a' || letter == 'A'){TextSrcRect.x = 0;   TextSrcRect.y = 0;}
  if(letter == 'b' || letter == 'B'){TextSrcRect.x = 16;  TextSrcRect.y = 0;}
  if(letter == 'c' || letter == 'C'){TextSrcRect.x = 32;  TextSrcRect.y = 0;}
  if(letter == 'd' || letter == 'D'){TextSrcRect.x = 48;  TextSrcRect.y = 0;}
  if(letter == 'e' || letter == 'E'){TextSrcRect.x = 64;  TextSrcRect.y = 0;}
  if(letter == 'f' || letter == 'F'){TextSrcRect.x = 80;  TextSrcRect.y = 0;}
  if(letter == 'g' || letter == 'G'){TextSrcRect.x = 96;  TextSrcRect.y = 0;}
  if(letter == 'h' || letter == 'H'){TextSrcRect.x = 112;  TextSrcRect.y = 0;}
  if(letter == 'i' || letter == 'I'){TextSrcRect.x = 128;  TextSrcRect.y = 0;}
  if(letter == 'j' || letter == 'J'){TextSrcRect.x = 144;  TextSrcRect.y = 0;}
  if(letter == 'k' || letter == 'K'){TextSrcRect.x = 160; TextSrcRect.y = 0;}
  if(letter == 'l' || letter == 'L'){TextSrcRect.x = 176; TextSrcRect.y = 0;}
  if(letter == 'm' || letter == 'M'){TextSrcRect.x = 192; TextSrcRect.y = 0;}
  if(letter == 'n' || letter == 'N'){TextSrcRect.x = 208; TextSrcRect.y = 0;}
  if(letter == 'o' || letter == 'O'){TextSrcRect.x = 224; TextSrcRect.y = 0;}
  if(letter == 'p' || letter == 'P'){TextSrcRect.x = 240; TextSrcRect.y = 0;}
  if(letter == 'q' || letter == 'Q'){TextSrcRect.x = 256; TextSrcRect.y = 0;}
  if(letter == 'r' || letter == 'R'){TextSrcRect.x = 272; TextSrcRect.y = 0;}
  if(letter == 's' || letter == 'S'){TextSrcRect.x = 288; TextSrcRect.y = 0;}
  if(letter == 't' || letter == 'T'){TextSrcRect.x = 304; TextSrcRect.y = 0;}
  if(letter == 'u' || letter == 'U'){TextSrcRect.x = 320; TextSrcRect.y = 0;}
  if(letter == 'v' || letter == 'V'){TextSrcRect.x = 336; TextSrcRect.y = 0;}
  if(letter == 'w' || letter == 'W'){TextSrcRect.x = 352; TextSrcRect.y = 0;}
  if(letter == 'x' || letter == 'X'){TextSrcRect.x = 368; TextSrcRect.y = 0;}
  if(letter == 'y' || letter == 'Y'){TextSrcRect.x = 384; TextSrcRect.y = 0;}
  if(letter == 'z' || letter == 'Z'){TextSrcRect.x = 400; TextSrcRect.y = 0;}

  if(letter == ' '){TextSrcRect.x = 0;   TextSrcRect.y = 32;}
  if(letter == '0'){TextSrcRect.x = 16;  TextSrcRect.y = 32;}
  if(letter == '1'){TextSrcRect.x = 32;  TextSrcRect.y = 32;}
  if(letter == '2'){TextSrcRect.x = 48;  TextSrcRect.y = 32;}
  if(letter == '3'){TextSrcRect.x = 64;  TextSrcRect.y = 32;}
  if(letter == '4'){TextSrcRect.x = 80;  TextSrcRect.y = 32;}
  if(letter == '5'){TextSrcRect.x = 96;  TextSrcRect.y = 32;}
  if(letter == '6'){TextSrcRect.x = 112; TextSrcRect.y = 32;}
  if(letter == '7'){TextSrcRect.x = 128; TextSrcRect.y = 32;}
  if(letter == '8'){TextSrcRect.x = 144; TextSrcRect.y = 32;}
  if(letter == '9'){TextSrcRect.x = 160; TextSrcRect.y = 32;}

  if(letter == 'Ä'){TextSrcRect.x = 176; TextSrcRect.y = 32;}
  if(letter == 'Ö'){TextSrcRect.x = 192; TextSrcRect.y = 32;}
  if(letter == 'Ü'){TextSrcRect.x = 208; TextSrcRect.y = 32;}
  if(letter == 'ä'){TextSrcRect.x = 224; TextSrcRect.y = 32;}
  if(letter == 'ö'){TextSrcRect.x = 240; TextSrcRect.y = 32;}
  if(letter == 'ü'){TextSrcRect.x = 256; TextSrcRect.y = 32;}

  if(letter == '.'){TextSrcRect.x = 0;   TextSrcRect.y = 48;}
  if(letter == ','){TextSrcRect.x = 16;  TextSrcRect.y = 48;}
  if(letter == '?'){TextSrcRect.x = 32;  TextSrcRect.y = 48;}
  if(letter == '!'){TextSrcRect.x = 48;  TextSrcRect.y = 48;}
  if(letter == '\''){TextSrcRect.x = 64;  TextSrcRect.y = 48;}
  if(letter == '-'){TextSrcRect.x = 80;  TextSrcRect.y = 48;}
  if(letter == '+'){TextSrcRect.x = 96;  TextSrcRect.y = 48;}
  if(letter == '*'){TextSrcRect.x = 112;  TextSrcRect.y = 48;}
  if(letter == '/'){TextSrcRect.x = 128;  TextSrcRect.y = 48;}
  if(letter == '"'){TextSrcRect.x = 144;  TextSrcRect.y = 48;}
  if(letter == '('){TextSrcRect.x = 160; TextSrcRect.y = 48;}
  if(letter == ')'){TextSrcRect.x = 176; TextSrcRect.y = 48;}
  if(letter == '='){TextSrcRect.x = 192; TextSrcRect.y = 48;}
  if(letter == ':'){TextSrcRect.x = 208; TextSrcRect.y = 48;}

  if(letter == '<'){TextSrcRect.x = 224; TextSrcRect.y = 48;} // UNCHECKED BOX
  if(letter == '>'){TextSrcRect.x = 240; TextSrcRect.y = 48;} // CHECKED BOX

  //if(colour<4){TextSrcRect.y += colour*40;}

  TextSrcRect.x += 320;

  SDL_RenderCopyEx( gRenderer, fontTexture, &TextSrcRect, &TextDstRect, charDegree, NULL, SDL_FLIP_NONE );
  letter = ' ';
}

// ##############################################
// ##############################################
// ##############################################
