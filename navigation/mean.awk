#!/usr/bin/awk -f
#
	{
	sum += $1;
	count++;
	}
END	{
    print (sum / count);
	}
