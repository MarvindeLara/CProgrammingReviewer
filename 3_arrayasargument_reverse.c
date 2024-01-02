/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	3_arrayasargument_reverse.c
*	Topic	: 	Array as argument
*	Task	: 	Array as argument
***************************************************************************/

#include <stdio.h>
#include <string.h>

void reverse_string(char test[]);

void reverse_string(char test[]) {

	int i;
	int j;
	char temp;
	
	for (i = 0, (j = strlen(test) - 1); j > i; i++, j--) {
		temp = test[j];
		test[j] = test[i];
		test[i] = temp;
	}
}

int main(int argc, char *argv[]) {

	char test[] = "Marvin De Lara";
	int i;
	
	for (i = 0; i < (strlen(test)); i++) {
		putchar(test[i]);
	}
	reverse_string(test);
	printf("\n%s\n", test);
	return 0;
}