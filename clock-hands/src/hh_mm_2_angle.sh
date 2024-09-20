#!/bin/bash
# Input:
# 10:10
#
# Time string in "hh:dd" format
# 12 hour clock
# No validation
# Quick 'n dirty
#
H=`echo $1 | cut -d ":" -f1`  
M=`echo $1 | cut -d ":" -f2`
#
units -t " 0.5 (60 $H + $M) - ($M * 6)"
