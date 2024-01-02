/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	8_searching_binarysearch.c
*	Topic	: 	Binary search
*	Task	: 	Binary search
***************************************************************************/

#include <stdio.h>

int binary_search(int a[], int item, size_t size);

int binary_search(int a[], int item, size_t size) {

	int low;
	int mid;
	int high;
	
	low = 0;
	high  = (size - 1);
	while (low <= high) {
		mid = (low + high) / 2;
		if (item < a[mid]) {
			high = mid - 1;
		} else if (item > a[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // array of ascending values 
	int item  = 7;							  // item to be searched
	size_t size = (sizeof(a)/sizeof(a[0]));   // size of array a
	int pos;								  // position of item in array a
	
	pos = binary_search(a, item, size);
	if (pos >= 0) {
		printf("Binary searching successful.\n");
		printf("%d is the %d-th element of array a.\n", item, pos);
		return 0;
	} else {
		printf("Binary searching unsuccessful.\n");
		printf("%d is not found in array a.\n", item);
		return -1;
	}
}