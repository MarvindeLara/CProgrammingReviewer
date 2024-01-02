/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	10_datastructure_linkedlist.c
*	Topic	: 	Data structures (linked list)
*	Task	: 	Data structures (linked list)
***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};
static struct nlist *hashtab[HASHSIZE];
struct table {
	char *name;
	char *defn;
} table_entries[] = {
	{"IN", "NEW"},
	{"OUT", "OLD"},
	{"ONGOING", "PROCESSING"},
	{"COMPLETED", "DONE"},
	{"MARVIN", ""},
	{"ONGOING", "IN PROCESS"}
};

char *strduplicate(char *s);
unsigned int hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);

char *strduplicate(char *s) {

	char *p;
	
	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy(p,s);
	}
	return p;
}

unsigned int hash(char *s) {

	unsigned int hashval;
	
	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
	
	struct nlist *np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0) {
			return np;
		}
	}
	return NULL;
}

struct nlist *install(char *name, char *defn) {
	
	struct nlist *np;
	unsigned int hashval;
	
	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if ((np == NULL) || ((np->name = strduplicate(name)) == NULL)) {
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval]; 
		hashtab[hashval] = np;
	} else {
		free((void *) np->defn);
	}
	if ((np->defn = strduplicate(defn)) == NULL) { 
		return NULL;
	}
	return np;
}

int main(int argc, char *argv[]) {

	int i;
	struct nlist *pnlist;
	char *test = "OUT";
	
	for (i = 0; i < ((sizeof(table_entries))/(sizeof(table_entries[0]))); i++) {
		pnlist = install(table_entries[i].name,table_entries[i].defn);
	}
	pnlist = lookup(test);
	if (pnlist != NULL) {
		printf("name: %s, definition: %s\n", pnlist->name, pnlist->defn);
	} else {
		printf("Name %s is not installed in hashtab.", test);
	}
	return 0;
}

