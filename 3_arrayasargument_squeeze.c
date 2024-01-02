/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	3_arrayasargument_squeeze.c
*	Topic	: 	Array as argument
*	Task	: 	Array as argument
***************************************************************************/

#include <stdio.h>

void squeeze_string(char test[], char a);

void squeeze_string(char test[], char a) {

	int i;
	int k;
	
	k = 0;
	for (i = 0; test[i] != '\0'; i++) {
		if (test[i] == a) {
		} else {
			test[k++] = test[i];
		}
	}
	test[k] = '\0';
}

int main(int argc, char *argv[]) {

	char test[] = "Marvin De Lara - Software Engineer, 09052087788";
	char a = 'a';
		
	squeeze_string(test, a);
	printf("The squeezed string is %s.\n", test);
	return 0;
}