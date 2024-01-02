/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	2_function_power.c
*	Topic	: 	Functions
*	Task	: 	Functions
***************************************************************************/

#include <stdio.h>

int power(int base, int expo);

int power(int base, int expo) {

	int p;

	for (p = 1; expo > 0; expo--)
		p = p * base;
	return p;
}

int main(int argc, char *argv[]) {

	int i;
	
	for (i = 0; i <= 10; i++)
		printf("%6d\t%6d\t%6d\n", i, power(2,i), power(-3, i));
	return 0; 
}