/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	4_arrayofpointers_sortlines.c
*	Topic	: 	Array of pointers
*	Task	: 	Array of pointers
***************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 1000

void write_lines(char *lineptr[], int nlines);
void swap(char *lineptr[], int i, int j);
void quick_sort(char *lineptr[], int left, int right);
char *alloc(int len);
int get_line(char line[], int maxlen);
int read_lines(char *lineptr[], int maxlines);

char *lineptr[MAXLINES];
char allocbuf[ALLOCSIZE]; 
char *allocp = allocbuf; 

void write_lines(char *lineptr[], int nlines) {
	
	while (nlines-- > 0) {
		printf("%s\n", *lineptr++);
	}
}

void swap(char *lineptr[], int i, int j) {

	char *temp;
	
	temp = lineptr[i];
	lineptr[i] = lineptr[j];
	lineptr[j] = temp;
}

void quick_sort(char *lineptr[], int left, int right) {

	int i;
	int last;
	
	if (left >= right) {
		return;
	}
	swap(lineptr, left, ((left + right) / 2));
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (strcmp(lineptr[i], lineptr[left]) < 0) {
			swap(lineptr, ++last, i);
		}
	}
	swap(lineptr, left, last);
	quick_sort(lineptr, left, last - 1);
	quick_sort(lineptr, last + 1, right);
	return;
}

char *alloc(int len) {

	if (allocbuf + ALLOCSIZE - allocp >= len) { 
		allocp = allocp + len; 
		return allocp - len; 
	} else {
		return NULL; 
	}
}

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

int read_lines(char *lineptr[], int maxlines) {

	int len;
	int nlines;
	char *p;
	char line[MAXLEN];
	
	nlines = 0;
	while((len = get_line(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			// remove new line
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

int main(int argc, char *argv[]) {

	int nlines;
	
	if ((nlines = read_lines(lineptr, MAXLINES)) >= 0) {
		quick_sort(lineptr, 0, nlines-1);
		write_lines(lineptr, nlines);
		return 0;
	} else {
		printf("Error: Input too big to sort.\n");
		return 1;
	}
}