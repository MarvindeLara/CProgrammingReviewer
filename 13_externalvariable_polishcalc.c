/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	13_externalvariable_polishcalc.c
*	Topic	: 	External variables
*	Task	: 	External variables
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

int bufp = 0;
char buf[BUFSIZE];
int sp = 0;
double val[MAXVAL];

void push(double op);
double pop(void);
int getch(void);
void ungetch(int c);
int getop(char s[]);

void push(double op) {

	if (sp < MAXVAL) {
		val[sp++] = op;
	} else {
		printf("push: Stack full, can't push %g\n", op);
	}
}

double pop(void) {

	if (sp > 0) {
		return val[--sp];
	} else {
		printf("pop: Stack is empty.\n");
		return 0.0;
	}
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

int getop(char s[]) {

	int i;
	int c;
	
	while ((s[0] = c = getch()) == ' ' || (c == '\t')) {
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		return c;
	}
	i = 0;
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch())) {;}
	}
	if (c == '.') {
		while (isdigit(s[++i] = c = getch())) {;}
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

int main(int argc, char *argv[]) {

	int type;
	double op2;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0) {
					push(pop() / op2);
				} else {
					printf("Error: Division by zero.\n");
				}
				break;
			case '\n':
				printf("Answer: %.8g\n", pop());
				break;
			default:
				printf("Error: Incorrect format of string %s\n", s);
				break;
		}
	}
	return 0;
}