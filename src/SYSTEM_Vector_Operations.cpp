#include "globals.h"

int PubCosAlpha;
int PubCosBeta;

// ##############################################
// ##############################################
// ##############################################

Vector3 vector_add(Vector3 *v, Vector3 *w)
{
  Vector3 a = {
      v->x+w->x,
      v->y+w->y,
      v->z+w->z};
  return a;
}

// ##############################################
// ##############################################
// ##############################################

// A simple yet powerful operation, lengths of a vector are
// used in a variety of the more complex vector matrix operations.
// Also, they can be used to determine the distance between two
// objects, by creating a vector from the subtraction of the two
// objects' coordinates and then taking the length of that vector
double vector_length(Vector3 *v)
{
  return (sqrt(v->x*v->x + v->y*v->y + v->z*v->z));
}


// ##############################################
// ##############################################
// ##############################################

// Normalizing a vector forms the basis of many more advanced
// vector operations. The process takes a vector of any length
// and preserves only its direction information
// (gives it a length of 1).
void vector_normalize(Vector3 *v)
{
  double len = vector_length(v);
  v->x /= len;
  v->y /= len;
  v->z /= len;
}


// ##############################################
// ##############################################
// ##############################################

// The dot product is very useful in game programming as it
// gives the angle between two vectors

// Auch für das Punktprodukt werden 2 Vektoren benötigt,
// jedoch muss es sich hier um zwei Normalvektoren handeln.
// Das Ergebnis ist diesmal aber kein dritter Vektor sondern
// eine Dezimalzahl die dem Kosinus der zwischen den beiden
// Vektoren eingeschlossen Winkel entspricht.
double vector_dot(Vector3 *v, Vector3 *w)
{
  return (v->x*w->x + v->y*w->y + v->z*w->z);
}

// ##############################################
// ##############################################
// ##############################################

// The cross product is a mathematical operation that will return a
// resultant vector that is orthogonal to the two vectors used to
// calculate it and has a length relative to the lengths of the
// vectors and the angles between them

// Um das Kreuzprodukt zu berechnen brauchen wir 2 Vektoren.
// Das Ergebnis ist ein dritter Vektor der Senkrecht auf den
// Beiden steht. Wenn wir um Beispiel das Kreuzprodukt aus
// der X-Achse(1, 0, 0) und der Y-Achse(0,1,0) berechnen so,
// erhalten wir die Z-Achse(0,0,1). Das Kreuzprodukt wird mit
// eine x zwischen den zwei gegebenen Vektoren dargestellt.
Vector3 vector_cross(Vector3 *v, Vector3 *w)
{
  Vector3 c = {
    v->y*w->z - v->z*w->y,
    v->z*w->x - v->x*w->z,
    v->x*w->y - v->y*w->x };
  return c;
}

// ##############################################
// ##############################################
// ##############################################

// returns a value between 0 and 31
// equals the sprite number to use to point the
// car in the direction of a vector
int vector_direction_32(Vector3 *v)
{
  int returnvalue = 0;

  double alpha;
  double beta;
  double cosalpha;
  double cosbeta;

  vector_normalize(v);
  cosalpha = v->y / sqrt(v->y*v->y +v->x*v->x);
  cosbeta = v->x / sqrt(v->y*v->y +v->x*v->x);

  alpha = acos(cosalpha) * 180 / 3.14159265;
  beta = acos(cosbeta) * 180 / 3.14159265;

  if(alpha >=  0 && alpha <=   6 && beta >=  84 && beta <=  96) {returnvalue=0;}  //straight up
  if(int(alpha) == 180 && int(beta)==90) {returnvalue=16;} // straight down (needed correction)

  if(alpha >=   6 && alpha <=  17 && beta >=  96 && beta <= 107) {returnvalue=1;}
  if(alpha >=  17 && alpha <=  28 && beta >= 107 && beta <= 118) {returnvalue=2;}
  if(alpha >=  28 && alpha <=  39 && beta >= 118 && beta <= 129) {returnvalue=3;}
  if(alpha >=  39 && alpha <=  50 && beta >= 129 && beta <= 140) {returnvalue=4;}
  if(alpha >=  50 && alpha <=  61 && beta >= 140 && beta <= 151) {returnvalue=5;}
  if(alpha >=  61 && alpha <=  72 && beta >= 151 && beta <= 162) {returnvalue=6;}
  if(alpha >=  72 && alpha <=  84 && beta >= 162 && beta <= 174) {returnvalue=7;}
  if(alpha >=  84 && alpha <=  96 && beta >= 174 && beta <= 180) {returnvalue=8;}  // right

  if(alpha >=  96 && alpha <= 107 && beta >= 162 && beta <= 174) {returnvalue=9;}
  if(alpha >= 107 && alpha <= 118 && beta >= 151 && beta <= 162) {returnvalue=10;}
  if(alpha >= 118 && alpha <= 129 && beta >= 140 && beta <= 151) {returnvalue=11;}
  if(alpha >= 129 && alpha <= 140 && beta >= 129 && beta <= 140) {returnvalue=12;}
  if(alpha >= 140 && alpha <= 151 && beta >= 118 && beta <= 129) {returnvalue=13;}
  if(alpha >= 151 && alpha <= 162 && beta >= 107 && beta <= 118) {returnvalue=14;}
  if(alpha >= 162 && alpha <= 174 && beta >=  96 && beta <= 107) {returnvalue=15;}
  //if(alpha >= 174 && alpha <= 180 && beta >=  84 && beta <=  96) {returnvalue=16;} // straight down

  if(alpha >= 174 && alpha <= 180 && beta >=  84 && beta <=  96) {returnvalue=16;} // straight down (neededcorrection)

  if(alpha >= 162 && alpha <= 174 && beta >=  72 && beta <=  84) {returnvalue=17;}
  if(alpha >= 151 && alpha <= 162 && beta >=  61 && beta <=  72) {returnvalue=18;}
  if(alpha >= 140 && alpha <= 151 && beta >=  50 && beta <=  61) {returnvalue=19;}
  if(alpha >= 129 && alpha <= 140 && beta >=  39 && beta <=  50) {returnvalue=20;}
  if(alpha >= 118 && alpha <= 129 && beta >=  28 && beta <=  39) {returnvalue=21;}
  if(alpha >= 107 && alpha <= 118 && beta >=  17 && beta <=  28) {returnvalue=22;}
  if(alpha >=  96 && alpha <= 107 && beta >=   6 && beta <=  17) {returnvalue=23;}
  if(alpha >=  84 && alpha <=  96 && beta >=   0 && beta <=   6) {returnvalue=24;} // left

  if(alpha >=  72 && alpha <=  84 && beta >=   6 && beta <=  17) {returnvalue=25;}
  if(alpha >=  61 && alpha <=  72 && beta >=  17 && beta <=  28) {returnvalue=26;}
  if(alpha >=  50 && alpha <=  61 && beta >=  28 && beta <=  39) {returnvalue=27;}
  if(alpha >=  39 && alpha <=  50 && beta >=  39 && beta <=  50) {returnvalue=28;}
  if(alpha >=  28 && alpha <=  39 && beta >=  50 && beta <=  61) {returnvalue=29;}
  if(alpha >=  17 && alpha <=  28 && beta >=  61 && beta <=  72) {returnvalue=30;}
  if(alpha >=   6 && alpha <=  17 && beta >=  72 && beta <=  84) {returnvalue=31;}


  return returnvalue;
}

// ##############################################
// ##############################################
// ##############################################


/*
  0 |  11 |  22 |  32 |  45 |  56 |  67 |  78
 90 | 101 | 112 | 122 | 135 | 146 | 157 | 168
180 | 191 | 202 | 212 | 225 | 236 | 247 | 258
270 | 281 | 292 | 302 | 315 | 326 | 337 | 348
*/

double angle[32];

void defineAngles()
{
  // a precalculation of all possible angles...
  angle[0] = 1.5*M_PI; // straight up
  angle[1] = 1.5*M_PI + 11*(M_PI/180); // top of the circle// straight up
  angle[2] = 1.5*M_PI + 22*(M_PI/180); // top of the circle// straight up
  angle[3] = 1.5*M_PI + 32*(M_PI/180); // top of the circle// straight up
  angle[4] = 1.5*M_PI + 45*(M_PI/180); // top of the circle// straight up
  angle[5] = 1.5*M_PI + 56*(M_PI/180); // top of the circle// straight up
  angle[6] = 1.5*M_PI + 67*(M_PI/180); // top of the circle// straight up
  angle[7] = 1.5*M_PI + 78*(M_PI/180); // top of the circle// straight up
  angle[8] = 1.5*M_PI + 90*(M_PI/180); // top of the circle// straight up
  angle[9] = 1.5*M_PI + 101*(M_PI/180); // top of the circle// straight up
  angle[10] = 1.5*M_PI + 112*(M_PI/180); // top of the circle// straight up
  angle[11] = 1.5*M_PI + 122*(M_PI/180); // top of the circle// straight up
  angle[12] = 1.5*M_PI + 135*(M_PI/180); // top of the circle// straight up
  angle[13] = 1.5*M_PI + 146*(M_PI/180); // top of the circle// straight up
  angle[14] = 1.5*M_PI + 157*(M_PI/180); // top of the circle// straight up
  angle[15] = 1.5*M_PI + 168*(M_PI/180); // top of the circle// straight up
  angle[16] = 1.5*M_PI + 180*(M_PI/180); // top of the circle// straight up
  angle[17] = 1.5*M_PI + 191*(M_PI/180); // top of the circle// straight up
  angle[18] = 1.5*M_PI + 202*(M_PI/180); // top of the circle// straight up
  angle[19] = 1.5*M_PI + 212*(M_PI/180); // top of the circle// straight up
  angle[20] = 1.5*M_PI + 225*(M_PI/180); // top of the circle// straight up
  angle[21] = 1.5*M_PI + 236*(M_PI/180); // top of the circle// straight up
  angle[22] = 1.5*M_PI + 247*(M_PI/180); // top of the circle// straight up
  angle[23] = 1.5*M_PI + 258*(M_PI/180); // top of the circle// straight up
  angle[24] = 1.5*M_PI + 270*(M_PI/180); // top of the circle// straight up
  angle[25] = 1.5*M_PI + 281*(M_PI/180); // top of the circle// straight up
  angle[26] = 1.5*M_PI + 292*(M_PI/180); // top of the circle// straight up
  angle[27] = 1.5*M_PI + 302*(M_PI/180); // top of the circle// straight up
  angle[28] = 1.5*M_PI + 315*(M_PI/180); // top of the circle// straight up
  angle[29] = 1.5*M_PI + 326*(M_PI/180); // top of the circle// straight up
  angle[30] = 1.5*M_PI + 337*(M_PI/180); // top of the circle// straight up
  angle[31] = 1.5*M_PI + 348*(M_PI/180); // top of the circle// straight up
}

// ##############################################
// ##############################################
// ##############################################

int getAngleNumber(double PiAngle)
{
  int ReturnValue = (int)((PiAngle*180/M_PI)/5.625);
  return ReturnValue;
}

// ##############################################
// ##############################################
// ##############################################
