/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	3_arrayasargument_atof.c
*	Topic	: 	Array as argument
*	Task	: 	Array as argument
***************************************************************************/

#include <stdio.h>
#include <ctype.h>

double string_convert(char number[]);

double string_convert(char number[]) {

	int i;
	double sign;
	double inumber;
	double power;
	
	sign = 1.0;
	for (i = 0; isspace(number[i]); i++) {
		;
	}
	if (number[i] == '-') {
		sign = -1.0;
	}
	if ((number[i] == '+') || (number[i] == '-')) {
		i++;
	}
	for (inumber = 0.0; isdigit(number[i]); i++) {
		inumber = 10.0 * inumber + (number[i] - '0');
	}
	if (number[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(number[i]); power *= 10, i++) {
		inumber = 10.0 * inumber + (number[i] - '0');
	}
	return (inumber * sign / power);
}

int main(int argc, char *argv[]) {

	char number[] = "    -1234.123";

	printf("The double-precision floating pt. equivalent is %f\n", string_convert(number));
	return 0;
}