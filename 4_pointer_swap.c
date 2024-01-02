//***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	4_pointer_swap.c
*	Topic	: 	Pointer
*	Task	: 	Pointer
***************************************************************************/

#include <stdio.h>

void swap(int *px, int *py);

void swap(int *px, int *py) {

	// pass pointers, but in function operate on values pointed to, not on pointers (address)
	// same concept as in arrays as arguments to function
	int temp;
	
	temp = *py;
	*py = *px;
	*px = temp;
	return;
}

int main(int argc, char *argv[]) {

	int x;
	int y;
	int *px;
	int *py;

	x = 3;
	y = 7;
	px = &x;
	py = &y;
	swap(px, py); // pass address of x and y, or pass pointers to x and y
	printf("x = %d, y = %d\n", x, y);
	return 0;
}