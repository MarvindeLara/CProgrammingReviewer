/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	1_switch_charcount.c
*	Topic	: 	Conditional expressions
*	Task	: 	Conditi0nal expressions
***************************************************************************/

#include <stdio.h>

#define IN  1
#define OUT 0

int main(int argc, char *argv[]) {
	
	int  i;
	int  c; 
	int  state;
	int  nlines;
	long nchars;
	long nwhite;
	long nother;
	int  ndigits[10];
	long nwords;

	
	state = OUT;
	nlines = 0;
	nchars = 0;
	nwhite = 0;
	nother = 0;
	nwords = 0;
	for (i = 0; i < ((sizeof(ndigits)/sizeof(ndigits[0]))); i++) {
		ndigits[i] = 0;
	}
	for (nchars = 0; ((c = getchar()) != EOF); putchar(c), nchars++) {
		switch (c) {
			case ' ':
			case '\t':
				state = OUT;
				nwhite++;
				break;
			case '\n':
				state = OUT;
				nlines++;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				ndigits[c - '0']++;
				if (state == OUT) {
					state = IN;
					nwords++;
				}
				break;
			default:
				nother++;
				if (state == OUT) {
					state = IN;
					nwords++;
				}
				break;
		}
	}
	printf("\nNumber of lines: %d", nlines);
	printf("\nNumber of characters: %ld", nchars);
	printf("\nNumber of words: %ld", nwords);
	printf("\nNumber of other characters: %ld", nother);
	printf("\nNumber of white spaces: %ld\n", nwhite);
	printf("0 1 2 3 4 5 6 7 8 9\n");
	for (i = 0; i < ((sizeof(ndigits)/sizeof(ndigits[0]))); i++) {
		printf("%d ", ndigits[i]);
	}
	return 0;
}