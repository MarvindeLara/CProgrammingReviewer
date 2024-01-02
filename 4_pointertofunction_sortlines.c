/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	4_pointertofunction_sortlines.c
*	Topic	: 	Pointer to function
*	Task	: 	Pointer to function
***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 1000

char *lineptr[MAXLINES];
char allocbuf[ALLOCSIZE]; 
char *allocp = allocbuf; 

void write_lines(char *lineptr[], int nlines);
int numcmp(char *s1, char *s2);
void swap(void *lineptr[], int i, int j);
void quicksort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
// comp is a pointer to a function with arguments including two pointers to void and returns an int
// pointing to void means pointing any data type
// as opposed to int *comp(void *, void *) which means that comp is a function that returns a pointer to int
char *alloc(int len);
int get_line(char line[], int maxlen);
int read_lines(char *lineptr[], int maxlines);

void write_lines(char *lineptr[], int nlines) {
	
	while (nlines-- > 0) {
		printf("%s\n", *lineptr++);
	}
	return;
}

int numcmp(char *s1, char *s2) {

	double v1;
	double v2;
	
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
		
}
void swap(void *lineptr[], int i, int j) {

	void * temp;
	
	temp = lineptr[i];
	lineptr[i] = lineptr[j];
	lineptr[j] = temp;
	return;
}

void quick_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *)) {

	int i;
	int last;
	
	if (left >= right) {
		return;
	}
	swap(lineptr, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (((*comp)(lineptr[i], lineptr[left])) < 0) {
			swap(lineptr, ++last, i);
		}
	}
	swap(lineptr, left, last);
	quick_sort(lineptr, left, last-1, comp);
	quick_sort(lineptr, last+1, right, comp);
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
	int numeric = 1;
	
	//if (argc > 1 && strcmp(argv[1], "-n") == 0)
	//	numeric = 1;
	if ((nlines = read_lines(lineptr, MAXLINES)) >= 0) {
		if (numeric == 0) {
			quick_sort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(strcmp));
		} else {
			quick_sort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(numcmp));
		}
		write_lines(lineptr, nlines);
		return 0;
	} else {
		printf("Input is too big to sort\n");
		return 1;
	}
}