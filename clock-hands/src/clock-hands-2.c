/*
Input
delta_theta in degrees (+ or -) {0..360}

Output
List all times in "00:00:00.000" format that match going through the (12 - 1) intervals around the clock

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
  int tmp_hour;
  double tmp_minute;

  delta_theta = strtod(argv[1], NULL);
  delta_theta = fmod(delta_theta, 360);
  for (hour = 1; hour <= 11; hour++)
    {
    minute = ( 2 * delta_theta + 60 * hour ) / 11;
    if (minute < 0)
      {
      tmp_minute = 60 + minute;
      tmp_hour = hour - 1;
      printf ("%02d:%02.f:%06.3f\n", tmp_hour, floor(tmp_minute), (tmp_minute - floor(tmp_minute)) * 60.0);
      }
    else if (minute >= 60)
        {
        tmp_minute = minute - 60;
        tmp_hour = hour + 1;
        printf ("%02d:%02.f:%06.3f\n", tmp_hour, floor(tmp_minute), (tmp_minute - floor(tmp_minute)) * 60.0);
        }
      else
        {
        printf ("%02d:%02.f:%06.3f\n", hour, floor(minute), (minute - floor(minute)) * 60.0);
        }
    }
  return 0;
  }
