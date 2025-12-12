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
units -t " 0.5 (60 $H + $M) - ($M * 6 + $S/60)"
