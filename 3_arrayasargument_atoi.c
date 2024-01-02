/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	3_arrayasargument_atoi.c
*	Topic	: 	Array as argument
*	Task	: 	Array as argument
***************************************************************************/

#include <stdio.h>
#include <ctype.h>

int string_convert(char number[]);

int string_convert(char number[]) {

	int i;
	int sign;
	int inumber;
	
	sign = 1;
	for (i = 0, inumber = 0; number[i] != '\0'; i++) {
		if (isspace(number[i])) {
			continue;
		}
		(number[i] == '-') ? sign = -1 : 0;
		if ((number[i] == '+') || (number[i] == '-')) {
			continue;
		}
		if (isdigit(number[i])) {
			inumber = 10 * inumber + (number[i] - '0');
		} else {
			printf("Error: String is not all digits.\n");
			return -1;
		}
	}
	return (inumber * sign);
}

int main(int argc, char *argv[]) {

	char number[] = "    -1234";

	printf("The integer equivalent is %d.\n", string_convert(number));
	return 0;
}