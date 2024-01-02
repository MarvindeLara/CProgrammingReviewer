/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	3_arrayasargument_printlongestline.c
*	Topic	: 	Array as argument
*	Task	: 	Array as argument
***************************************************************************/

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void save_line(char longest[], char line[]);

void save_line(char longest[], char line[]) {

	int i;
	
	i = 0;
	while ((longest[i] = line[i]) != '\0') {
		i++;	
	}
}

int get_line(char line[], int maxline) {

	int c;
	int nchar;
	
	for (nchar = 0; ((nchar <= maxline) && ((c = getchar()) != EOF) && (c != '\n')); nchar++)
		line[nchar] = c;
	if (c == '\n') {
		line[nchar++] = c;
	}
	line[nchar] = '\0';
	return nchar;
}

int main(int argc, char *argv[]) {

	int length;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((length = get_line(line, MAXLINE)) > 0) {
		if (length > max) {
			save_line(longest, line);
			max = length;
		}
	}
	printf("Longest line: %s", longest);
	printf("Length: %d\n", max);
	return 0;
}