#!/usr/bin/awk -f
#
# https://en.wikipedia.org/wiki/Average_absolute_deviation
# aka:
# mean absolute deviation (MAD)
# -v m=$mean

#
function abs(x) 
	{
	return (x >= 0) ? x : -x 
	}
	#
#
	{
	abs_deviation_sum += abs($1 - m);
	}
END	{
	print (abs_deviation_sum / NR);
	}

