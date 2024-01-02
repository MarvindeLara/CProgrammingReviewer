/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	10_datastructure_trees.c
*	Topic	: 	Data structures (trees)
*	Task	: 	Data structures (trees)
***************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

int bufp = 0;
char buf[BUFSIZE];
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
	// It is illegal for a structure to contain an instance of itself.
};

void tree_print(struct tnode *p);
char *strduplicate(char *s);
struct tnode *talloc(void);
struct tnode *add_tree(struct tnode *p, char *w);
int getch(void);
void ungetch(int);
int get_word(char *word, int lim);

void tree_print(struct tnode *p) {
	
	if (p != NULL) {
		tree_print(p->left);
		printf("%4d %s\n", p->count, p->word);
		tree_print(p->right);
	}
}

char *strduplicate(char *s) {

	char *p;
	
	p = (char *) malloc(strlen(s) + 1); //+1 for \0 character
	if (p != NULL) {
		strcpy(p,s);
	}
	return p;
}

struct tnode *talloc(void) {
	
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *add_tree(struct tnode *p, char *w) {

	int cond;
	
	if (p == NULL) {
		p = talloc();
		p->word = strduplicate(w);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;
	} else if (cond < 0) {
		p->left = add_tree(p->left, w);
	} else {
		p->right = add_tree(p->right, w);
	}
	return p;
}

int getch(void) {

	if (bufp > 0) {
		return buf[--bufp];
	} else {
		return (getchar());
	}	
}

void ungetch(int c) {

	if (bufp >= BUFSIZE) {
		printf("ungetch: Too many characters.\n");
	} else {
		buf[bufp++] = c;
	}
}

int get_word(char *word, int lim) {
	
	int c;
	char *w = word;
	
	while (isspace(c = getch())) {
		;
	}
	if (c != EOF) {
		*w++ = c;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0]; // interchangeable char and int in this case
}

int main(int argc, char *argv[]) {

	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (get_word(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			root = add_tree(root, word);
		}
	}
	tree_print(root);
	return 0;
}