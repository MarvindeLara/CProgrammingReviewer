/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	3_arrayasargument_itoa.c
*	Topic	: 	Array as argument
*	Task	: 	Array as argument
***************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXSIZE 10

void number_convert(int number, char snumber[]);
void reverse_string(char snumber[]);

void reverse_string(char snumber[]) {

	int i;
	int j;
	char temp;
	
	for (i = 0, (j = strlen(snumber) - 1); j > i; i++, j--) {
		temp = snumber[j];
		snumber[j] = snumber[i];
		snumber[i] = temp;
	}
}

void number_convert(int number, char snumber[]) {

	int i;
	int sign;
	
	i = 0;
	sign = number;
	(sign < 0) ? number = -(number) : 0;
	do {
		snumber[i++] = number % 10 + '0';
	} while (number /= 10);
	(sign < 0) ? snumber[i++] = '-' : 0;
	snumber[i] = '\0';
}

int main(int argc, char *argv[]) {

	char snumber[MAXSIZE];
	int number;

	number = 1234;
	number_convert(number, snumber);
	reverse_string(snumber);
	printf("%s\n", snumber);
	return 0;
}