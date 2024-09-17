/*
Calculate angle between hour hand and minute hand on an analogue clock.
Enumerate all 720 minutes over 12 hours

https://en.wikipedia.org/wiki/Clock_angle_problem

Interactive clock to experiment with
https://toytheater.com/clock/

For hands alignment (requires seconds):
https://upload.wikimedia.org/wikipedia/commons/1/1a/Clock_angle_problem_graph.svg

*/
#include <stdio.h>
#include <stdlib.h>

#define hour_hand_distance (360.0/(12*60))
#define minute_hand_distance (360.0/60)
int main()
  {
  int i;
  int hour;
  int minute;
  int minute_sigma;
  double angle_between_hands;

  for (i = 0; i < (12*60); i++)
    {
    hour = i/60;
    minute = i%60;
    minute_sigma = (60 * hour + minute);
    angle_between_hands = (minute_hand_distance * minute) - (hour_hand_distance * minute_sigma);
    printf ("%02d:%02d %4.2f\n", hour, minute, angle_between_hands);
    }
  return 0;
  }
