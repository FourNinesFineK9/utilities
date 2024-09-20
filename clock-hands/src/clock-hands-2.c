/*
Input
delta_theta in degrees (+ or -) {0..360}

Output
In "00:00:00.000" format going through the (12 - 1) intervals around the clock

https://en.wikipedia.org/wiki/Clock_angle_problem

(delta_theta > 0), hour hand ahead
(delta_theta == 0), conjunction
(delta_theta < 0), minute hand ahead

Interactive clock to experiment with
https://toytheater.com/clock/

To pick out patterns wtih granularity: seconds:
https://upload.wikimedia.org/wikipedia/commons/1/1a/Clock_angle_problem_graph.svg

Fencepost problem
https://en.wikipedia.org/wiki/Off-by-one_error

12 posts
11 intervals

Set
first post (of the fence) to fence_post_first
last post (of the fence) to fence_post_last

By inspection of the results:
intervals spaced by
delta_time
=
Travel time around the 12 hour clock divided by 11

Using GNU units and qalc:

linux> units -t day
24 hr = 86400 s
linux> units -t "(1 day / 2) / 11"
3927.2727 s
linux> units -t "(1 day / 2) / 11" hms
1;5;27.272727
linux> units -t "1 hour + 5 minute + 27.272727 seconds"
3927.2727 s
delta_time = "01:05:27.27"
linux> units -t "5 minute + 27.272727 seconds"
327.27273 s
linux> units -t "27.272727 seconds" minute
0.45454545
linux> units -t "1 hour + (60/11) minutes" hms
1;5;27.272727
linux> qalc "60/11"
60 / 11 = 5 + 5/11 ≈ 5.454545455
linux> qalc "(60/11 - 5 ) * 60"
((60 / 11) − 5) × 60 = 300/11 = 27 + 3/11 ≈ 27.27272727

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
  {
  double delta_theta;

  int hour;
  double minute;
  int i;
  double j;

  int fence_post_first = 1;
  int fence_post_last = 12;

  delta_theta = strtod(argv[1], NULL);
  delta_theta = fmod(delta_theta, 360);
  for (i = fence_post_first; i < fence_post_last; i++)
    {
    j = (60 * i  - (2 * delta_theta) ) / 11;
    if (j < 0)
      {
      hour = i - 1;
      minute = 60 + j;
      }
    else if (j >= 60)
      {
      hour = i + 1;
      minute = j - 60;
      }
      else
        {
        hour = i;
        minute = j;
        }
    printf ("%02d:%02.f:%06.3f\n", hour, floor(minute), (minute - floor(minute)) * 60.0);
    }
  return 0;
  }
