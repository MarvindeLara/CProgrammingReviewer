/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	4_pointertostructure_wordsearch.c
*	Topic	: 	Pointer to structure
*	Task	: 	Pointer to structure
***************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))
#define BUFSIZE 100

struct key {
	char *word;
	int count;
} keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0}
	/*in main(), it is important to sort strings 
	into increasing order(lexicographically) before doing a searching algorithm*/
};
int bufp = 0;
char buf[BUFSIZE];

struct key *bin_search(char *word, struct key *keytab, int n);
void ungetch(int c);
int getch(void);
int get_word(char *word, int lim);

struct key *bin_search(char *word, struct key *keytab, int n) {
	
	int cond;
	struct key *low = &keytab[0];
	struct key *high = &keytab[n];
	struct key *mid;
	
	while (low < high) {
		mid  = low + ((high-low)/2);
		if ((cond = strcmp(word, mid->word)) < 0) {
			high = mid;
		} else if (cond > 0) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return NULL;
}

int getch(void) {

	if (bufp > 0) {
		return buf[--bufp];
	} else {
		return (getchar());
	}	
}

void ungetch(int c) {

	if (bufp >= BUFSIZE) {
		printf("ungetch: Too many characters.\n");
	} else {
		buf[bufp++] = c;
	}
}

int get_word(char *word, int lim) {
	
	int c;
	char *w = word;
	
	while (isspace(c = getch())) {
		;
	}
	if (c != EOF) {
		*w++ = c;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0]; // interchangeable char and int in this case
}

int main(int argc, char *argv[]) {
	
	char word[MAXWORD];
	struct key *p;
	
	while (get_word(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			if ((p = bin_search(word, keytab, NKEYS)) != NULL) {
				p->count++;
			}
		}
	}
	for (p = keytab; p < keytab + NKEYS; p++) {
		if (p->count >= 0) {
			printf("%4d %s\n", p->count, p->word);
		}
	}
	return 0;
}