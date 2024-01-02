/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	4_pointerasargument_getint.c
*	Topic	: 	Pointer as argument (WITH ERROR)
*	Task	: 	Pointer as argument
***************************************************************************/

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 100

int getch(void);
void ungetch(int c);
int getint(int *testn);

int bufp = 0;
char buf[BUFSIZE];

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

int get_int(int *testn) {

	int c;
	int sign;
	
	sign = 1;
	while (isspace(c = getch())) {
		;
	}
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		*testn = 0;
		return 0;
	}
	if (c == '-') {
		sign = -1;
	}
	if (c == '-' || c == '+') {
		c = getch();
	}
	for (*testn = 0; isdigit(c); c = getch()) {
		*testn = 10 * *testn + (c - '0');
	}
	*testn *= sign;
	if (c != EOF) {
		ungetch(c);
	} else {
		*testn = '\0';
	}
	return c;
}

int main(int argc, char *argv[]) {

	int n;
	int test[SIZE];
	
	for (n = 0; (n < SIZE) && (get_int(&test[n]) != EOF); n++) {
		;
	} 
	for (n = 0; test[n] != '\0'; n++)
		printf("%d ", test[n]);
	return 0;
}