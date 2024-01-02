/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	9_sorting_quicksort.c
*	Topic	: 	Quick sort
*	Task	: 	Quick sort
***************************************************************************/

#include <stdio.h>

void quick_sort(int v[], int left, int right);
void swap(int v[], int i, int j);

void swap(int v[], int i, int j) {

	int temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	return;
}

void quick_sort(int v[], int left, int right) {

		int i;
		int last;
		
		if (left >= right) {
			return;
		}
		swap(v, left, ((left + right) / 2));
		last = left;
		for (i = left + 1; i <= right; i++) {
			if (v[i] < v[left]) {
				swap(v, ++last, i);
			}
		}
		swap(v, left, last);
		quick_sort(v, left, last - 1);
		quick_sort(v, last + 1, right);
		return;
}

int main(int argc, char *argv[]) {

	int v[] = {1, 5, 3, 7, 4, 0};
	// used to indicate position of elements to be sorted (from v[left] to v[right])
	int left = 0;
	int right = 5;
	int i;
	
	quick_sort(v, left, right);
	printf("The sorted array (increasing) is: ");
	for (i = 0; i < (sizeof(v)/sizeof(v[0])); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}