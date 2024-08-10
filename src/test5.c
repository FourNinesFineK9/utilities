/*
Input:
4 space delimited LATLONG angles in decimal degrees

Output:
Bearing in degrees wrt North
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

int main(int argc, char *argv[])
  {
  float rlat1,rlat2,rlong1,rlong2,rresult;
  float dresult;

  rlat1  = degToRad(strtod(argv[1], NULL));
  rlong1 = degToRad(strtod(argv[2], NULL));
  rlat2  = degToRad(strtod(argv[3], NULL));
  rlong2 = degToRad(strtod(argv[4], NULL));

  rresult = atan(
				(sinf(rlong2 - rlong1) * cosf(rlat2)) /
				((cosf(rlat1) * sinf(rlat2)) - (sinf(rlat1) * cosf(rlat2) * cosf(rlong2 - rlong1)))
				);
  dresult = radToDeg(rresult);

  printf("%.5lf\n", dresult);
  return 0;
  }
