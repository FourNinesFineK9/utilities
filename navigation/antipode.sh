#
# Input: lat/long pair of a point on Planet Earth in decimal
# Output: lat/long of antipodal point
# No validation of input
#
# Compare with
# https://www.dcode.fr/antipodal-coordinates
#
# https://quickref.me/bash#bash-conditionals
#
# Test data:
#
# lat/long(BNA) =
# 36.124444
# 86.678056 
# 
# ./antipode.sh 36.124444 86.678056
# linux> ./src/antipode.sh 36.124444 86.678056
# SNIP------------------------------------------------------------------------
#
phi=$1
lambda=$2

anti_phi=`bc <<< "(-1)*$phi"`

if [[ $lambda > 0 ]]
then
	anti_lambda=`bc <<< "(-1)*(180-$lambda)"`
else
	anti_lambda=`bc <<< "(180+$lambda)"`
fi

printf "# %5.2f %5.2f\n" $anti_phi $anti_lambda
# -36.12 -93.32
# -5.00 -179.00
# SNIP------------------------------------------------------------------------
