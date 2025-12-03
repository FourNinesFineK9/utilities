/*
gcc -o calc-tax ../src/calc-tax.c -lm
Usage: 
./calc-tax VermögenssteuerTarife 500000

Data file should contain absolute bounds, not delta values

Format:
rate bound
Sample:

linux> cat VermögenssteuerTarife 
0.0000 80000
0.0005 318000
0.0010 717000
0.0015 1353000
0.0020 2309000
0.0025 3262000
0.0030 9999999

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
  {
  FILE *file;
  double brackets [50][2];
  int i;
  int j;
  double previous_bound;
  double remaining_amount;
  double slice;
  double taxable_amount;
  double tax_for_this_slice;
  double total_tax;

  file = fopen(argv[1], "r");
 
  i=0;
  while (fscanf(file, "%lf %lf", &brackets[i][0], &brackets[i][1]) != EOF)
    {
    i++;
    }
  fclose(file);

  previous_bound = 0;
  total_tax = 0; 
  taxable_amount = strtod(argv[2], NULL);
  tax_for_this_slice = 0;
  remaining_amount = taxable_amount;

  j = 0;
  while (remaining_amount >= 0.0001)
    {
    slice = fmin ((brackets[j][1] - previous_bound), remaining_amount);
    remaining_amount = remaining_amount - slice; 
    tax_for_this_slice = (slice * brackets[j][0]);  
    total_tax = total_tax + tax_for_this_slice;
    previous_bound = brackets[j][1];
    /*
    printf ("%8.lf %8.6lf %8.lf %4.lf\n", slice, brackets[j][0], remaining_amount, tax_for_this_slice);
    */
    j++;
    } 
  printf ("%.f\n", total_tax); 
  return 0;
  }

