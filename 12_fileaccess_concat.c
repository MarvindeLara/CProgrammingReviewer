/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	12_fileaccess_concat.c
*	Topic	: 	File access
*	Task	: 	File access
***************************************************************************/

#include <stdio.h>

/* char *fgets(char *line, int maxline, FILE *fp);
int fputs(char *line, FILE *fp);
int get_line(char *line, int max); */
void filecopy(FILE *ifp, FILE *ofp);

/* char *fgets(char *line, int maxline, FILE *fp) {

	register int c;
	register char *cs;
	
	cs = line;
	while (--maxline > 0 && (c = getc(fp)) != EOF) {
		if ((*cs++ = c) == '\n') {
			break;
		}
	}
	*cs = '\0';
	return (c == EOF && cs == line) ? NULL : line;
}

int fputs(char *line, FILE fp) {

	int c;
	
	while (c == *line++) {
		putc(c, fp);
	}
	return ferror(fp) ? EOF : 0;
}

int get_line(char *line, int max) {

	if (fgets(line, max, stdin) == NULL) {
		return 0;
	} else {
		return strlen(line);
	}
} */

void filecopy(FILE *ifp, FILE *ofp) {
	
	int c;
	
	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
	}
}

int main(int argc, char *argv[]) {
	
	FILE *fp;
	
	if (argc == 1) {
		filecopy(stdin, stdout);
	} else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	return 0;
}

/* #include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

   FILE *fp;
   char buff[255];

   fp = fopen("input.txt", "r");
   if(fp != NULL) {
      while (!feof(fp)) {
         memset(buff, '\0', sizeof(buff));
         fgets(buff, 255, (FILE*)fp);
         printf("%s", buff);
      }
      fclose(fp);
   }
} */
