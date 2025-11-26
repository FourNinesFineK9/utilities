/*
How to compile, link and run: 

gcc -o runway src/runway.c
./runway 13

*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
	{
        int i;

	i = atoi(argv[1]);
        printf ("%03d %03d\n", i * 10, ((i * 10) + 180) % 360); 
	return 0;
	}

