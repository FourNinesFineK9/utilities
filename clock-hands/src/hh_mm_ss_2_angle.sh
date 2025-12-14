#!/bin/bash
# Input:
# 10:10:10
#
# Time string in "hh:dd:ss" format
# 12 hour clock
# No validation
# Quick 'n dirty
#
# seconds added thanks to "Search Assist"
# https://duckduckgo.com/?q=Clock+angle+problems%2C+math+formula+with+seconds&t=brave&ia=web
#
H=`echo $1 | cut -d ":" -f1`  
M=`echo $1 | cut -d ":" -f2`
S=`echo $1 | cut -d ":" -f3`
#
time_in_seconds=`units -t " $H hour + $M minute + $S seconds" seconds`
time_in_seconds_from_top_of_the_hour=`units -t " $M minute + $S seconds" seconds`
hour_hand_angle=`units -t " $time_in_seconds * 360 degree / (12 * 60 * 60)" degree`
minute_hand_angle=`units -t " $time_in_seconds_from_top_of_the_hour * 360 degree / (1 * 60 * 60)" degree`
units -t " ( $hour_hand_angle - $minute_hand_angle ) degree" degree
