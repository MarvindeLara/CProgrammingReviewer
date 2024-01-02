/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	8_searching_binarysearch_pointers.c
*	Topic	: 	Binary search (pointers)
*	Task	: 	Binary search
***************************************************************************/

#include <stdio.h>
#include <string.h>

static int binsearch(char *str[], int max, char *value);

static int binsearch(char *str[], int max, char *value) {
	
	int position;
	int begin;
	int end;
	int cond;
	
	begin = 0;
	end = max - 1;
	while (begin <= end) {
		position = (begin + end) / 2;
		if ((cond = strcmp(value, str[position])) < 0) {
			end = position - 1;
		} else if ((cond = strcmp(value, str[position])) > 0) {
			begin = position + 1;
		} else {
			return position;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {

	char *strings[] = { "bill",
						"chris",
						"jason",
						"randy",
						"trish",
					  };
	int i;
	int asize;
	int result;
	
	i = asize = result = 0;
	asize = sizeof(strings)/sizeof(strings[0]);
	for (i = 0; i < asize; i++) {
		printf("%d: %s\n", i, strings[i]);
	}
	printf("\n");
	if ((result = binsearch(strings, asize, "randy")) != -1) {
		printf("'randy' found at position: %d\n", result);
	} else {
		printf("'randy' NOT found.\n");
	}
	return 0;
}