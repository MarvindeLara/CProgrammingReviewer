/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	9_sorting_shellsort.c
*	Topic	: 	Shell sort
*	Task	: 	Shell sort
***************************************************************************/

#include <stdio.h>

void shell_sort(int a[], size_t size);

void shell_sort(int a[], size_t size) {

	int gap;
	int i;
	int j;
	int temp;
	
	for (gap = size / 2; gap > 0; gap /= 2) {
		for (i = gap; i < size; i++) {
			for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) {
				temp = a[j];
				a[j] = a[j + gap];
				a[j + gap] =  temp;
			}
		}
	}
	return;
}

int main(int argc, char *argv[]) {

	int a[] = {0, 3, 1, 4, 6, 2};
	size_t size = (sizeof(a) / sizeof(a[0]));
	int i;

	shell_sort(a, size);
	printf("The sorted array (increasing) is: ");
	for (i = 0; i <= size - 1; i++) { 
		printf("%d ", a[i]);
	}
	return 0;
}