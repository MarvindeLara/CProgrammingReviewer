/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	11_commandlinearg_grep.c
*	Topic	: 	Command line arguments
*	Task	: 	Command line arguments
***************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char line[], int maxlen);

int get_line(char line[], int maxlen) {

	int c;
	int nchar;
	
	for (nchar = 0; ((nchar <= maxlen) && ((c = getchar()) != EOF) && (c != '\n')); nchar++)
		line[nchar] = c;
	if (c == '\n') {
		line[nchar++] = c;
	}
	line[nchar] = '\0';
	return nchar;
}

int main(int argc, char *argv[]) {

	int c;
	char line[MAXLINE];
	int found;
	long lineno;
	int except;
	int number;
	
	found = 0;
	lineno = 0;
	except = 0;
	number = 0;
	while (--argc > 0 && (*++argv)[0] == '-') {
		while (c = *++argv[0]) {
			switch(c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("Illegal option %c\n", c);
					break;
			}
		}		
	}
	if (argc != 1) {
		printf("Usage: find -x -n pattern\n");
	} else {
		while (get_line(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number) {
					printf("%ld: ", lineno);
				}
				printf("%s", line);
				found++;
			}
		}
	}
	return found;
}
