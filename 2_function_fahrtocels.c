/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	2_function_fahrtocels.c
*	Topic	: 	Functions
*	Task	: 	Functions
***************************************************************************/

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void celsius2fahr(void);
void fahr2celsius(void);

void celsius2fahr(void) {

	float celsius;
	float fahr;
	
	printf("\nCelsius-Fahrenheit Table\n");
	for (celsius = LOWER; celsius <= UPPER; celsius += STEP) {
		fahr = (celsius * 9.0 / 5.0) + 32.0;
		printf("%3.1f          %6.2f\n", celsius, fahr);
	}
	return;
}

void fahr2celsius(void) {

	int celsius;
	int fahr;
	
	printf("Fahrenheit-Celsius Table\n");
	for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%3d          %6d\n", fahr, celsius);
	}
	return;
}

int main(int argc, char *argv[]) {

	fahr2celsius();
	celsius2fahr();
	return 0;
}