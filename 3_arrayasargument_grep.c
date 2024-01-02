/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	3_arrayasargument_grep.c
*	Topic	: 	Array as argument
*	Task	: 	Array as argument
***************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int find_pattern(char line[], char pattern[]);
int get_line(char line[], int maxline);

int find_pattern(char line[], char pattern[]) {

	int i;
	int j;
	
	for (i = 0; line[i] != '\0'; i++) {
		for (j = 0; (line[i] == pattern[j]) || (pattern[j] == '\0'); j++, i++) {
			if (pattern[j] == '\0') {
				return (i - strlen(pattern));
			}
		}
	}
	return -1;
}

int get_line(char line[], int maxline) {

	int c;
	int nchars;
	
	for (nchars = 0; ((nchars <= maxline) && ((c = getchar()) != EOF) && (c != '\n')); nchars++) {
		line[nchars] = c;
	}
	if (c == '\n') {
		line[nchars++] = c;
	}
	line[nchars] = '\0';
	return nchars;
}

int main(int argc, char *argv[]) {

	int length;
	int pfound;
	char line[MAXLINE];
	char pattern[] = "Marvin";
	
	while ((length = get_line(line, MAXLINE)) > 0) {
		if ((pfound = find_pattern(line, pattern)) >= 0) {
			printf("%s", line);
		}
	}
	return 0;
}