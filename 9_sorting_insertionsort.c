/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	9_sorting_insertionsort.c
*	Topic	: 	Insertion sort (linked list) (WITH ERROR)
*	Task	: 	Insertion sort
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int number;
	struct node *next;
};
struct node *head = NULL;

void insert_node(int value);

void insert_node(int value) {

	struct node *temp = NULL;
	struct node *one = NULL;
	struct node *two = NULL;
	
	if (head == NULL) {
		head = (struct node *)malloc(sizeof(struct node *));
		head->next = NULL; 
	}
	one = head;
	two = head->next;
	temp = (struct node *)malloc(sizeof(struct node *));
	temp->number = value;
	while ((two != NULL) && (temp->number < two->number)) {
		one = one->next;
		two = two->next;
	}
	one->next = temp;
	temp->next = two;
	return;
}

int main (int argc, char *argv[]) {
	
	struct node *current = NULL;
	struct node *next = NULL;
	int test[] = {8, 3, 2, 6, 1, 5, 4, 7, 9, 0};
	int i;
	
	for (i = 0; i < (sizeof(test)/sizeof(test[0])); i++) {
		insert_node(test[i]);
	}
	printf(" Before  After\n");
	i = 0;
	while (head->next != NULL) {
		printf("%4d\t%4d\n", test[i++], head->number);
		head = head->next;
	}
	for (current = head; current != NULL; current = next) {
		next = current->next;
		free(current);
	}
	return 0;
}