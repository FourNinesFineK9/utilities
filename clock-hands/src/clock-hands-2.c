/*
Input
delta_theta in degrees (+ or -) {0..360}

Output
In "00:00:00.000" format going through the (12 - 1) intervals around the clock

https://en.wikipedia.org/wiki/Clock_angle_problem

Interactive clock to experiment with
https://toytheater.com/clock/

For hands alignment (require seconds):
https://upload.wikimedia.org/wikipedia/commons/1/1a/Clock_angle_problem_graph.svg
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define hour_hand (360.0/(12*60))
#define minute_hand (360.0/60)

int main(int argc, char *argv[])
  {
  double delta_theta;
  int hour;
  double minute;
  int thour;
  double tminute;

  delta_theta = strtod(argv[1], NULL);
  delta_theta = fmod(delta_theta, 360);
  if (delta_theta <= 0)
    {
    delta_theta = 360 + delta_theta;
    }
  for (hour = 1; hour <= 11; hour++)
    {
    minute = (60 * hour  - (2 * delta_theta) ) / 11;
    if (minute < 0)
      {
      tminute = 60 + minute;
      thour = hour - 1;
      }
    else
      {
      tminute = minute;
      thour = hour;
      }
    printf ("%02d:%02.f:%06.3f\n", thour, floor(tminute), (tminute - floor(tminute)) * 60.0);
    }
  if (delta_theta > 360/2)
    {
    printf ("%06.3f\n", delta_theta - 360.0);
    }
  else
    {
    printf ("%06.3f\n", delta_theta);
    }
  return 0;
  }
