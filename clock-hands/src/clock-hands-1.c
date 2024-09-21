/*
Calculate angle between hour hand and minute hand on an analogue clock.
Enumerate all 720 minutes over 12 hours
Granularity: integer minutes

https://en.wikipedia.org/wiki/Clock_angle_problem

Interactive clock to experiment with
https://toytheater.com/clock/

Define angle between clock hands:
delta_theta = theta[Hour Hand] - theta [Minute Hand]
Keep the sign (unlike in the Wiki article just quoted)  

(delta_theta > 0), hour hand ahead
(delta_theta == 0), conjunction
(delta_theta < 0), minute hand ahead

Angles are measured wrt North (12 o'clock). Same as in navigation bearings.
Unlike maths quadrants (which start from East, or (1,0) on a unit circle.

Compile and run under linux:

gcc -o clock-hands-1 src/clock-hands-1.c
./clock-hands-1

*/
#include <stdio.h>

#define hour_hand_distance (360.0/(12*60))
#define minute_hand_distance (360.0/60)
#define minutes_per_half_day (60*12)
#define minutes_per_hour (60)
int main()
  {
  int j;
  int hour;
  int minute;
  int minute_sigma;
  double angle_between_hands;

  for (j = 0; j < minutes_per_half_day; j++)
    {
    hour = j / minutes_per_hour;
    minute = j % minutes_per_hour;
    minute_sigma = (minutes_per_hour * hour + minute);
    angle_between_hands = (hour_hand_distance * minute_sigma) - (minute_hand_distance * minute);
    printf ("%02d:%02d %4.2f\n", hour, minute, angle_between_hands);
    }
  return 0;
  }
