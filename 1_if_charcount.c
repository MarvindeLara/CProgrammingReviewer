/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	1_if_charcount.c
*	Topic	: 	Conditional expressions
*	Task	: 	Conditional expressions
***************************************************************************/

#include <stdio.h>

#define IN  1
#define OUT 0

int main(int argc, char *argv[]) {

	int  i;
	int  c; 
	// we cannot use char because c must be big enough to hold value of EOF
	int  state;
	int  nlines;
	long nchars;
	long nwords;
	int  ndigits[10];

	state = OUT;
    nlines = 0;
	nwords = 0;
	for (i = 0; i < ((sizeof(ndigits)/sizeof(ndigits[0]))); i++) {
		ndigits[i] = 0;
	}
	for (nchars = 0; ((c = getchar()) != EOF); putchar(c), nchars++) {
		(c == '\n') ? nlines++ : 0;
		(c >= '0' && c <= '9') ? ndigits[c - '0']++ : 0;
		if ((c == ' ') || (c == '\t') || (c == '\n')) {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			nwords++;
		}
	}
	printf("\nNumber of lines: %d", nlines);
	printf("\nNumber of characters: %ld", nchars);
	printf("\nNumber of words: %ld\n", nwords);
	printf("0 1 2 3 4 5 6 7 8 9\n");
	for (i = 0; i < ((sizeof(ndigits)/sizeof(ndigits[0]))); i++) {
		printf("%d ", ndigits[i]);
	}
	return 0;
}