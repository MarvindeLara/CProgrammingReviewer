/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	5_addressarithmetic_allocstorage.c
*	Topic	: 	Address arithmetic
*	Task	: 	Address arithmetic
***************************************************************************/

#include <stdio.h>

#define ALLOCSIZE 1000

char *alloc(int n);
void afree(char *p);

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; //next free position is the start

char *alloc(int n) {
   
	if (allocbuf + ALLOCSIZE - allocp >= n) { 
		allocp = allocp + n; 
		return allocp - n; 
	} else {
		return NULL; 
	}
}

void afree(char *p) {

	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
			allocp = p;
	}
	return;
}
