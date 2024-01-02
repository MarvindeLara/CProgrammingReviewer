/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	11_commandlinearg_echo.c
*	Topic	: 	Command line arguments
*	Task	: 	Command line arguments
***************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	while (--argc > 0)
		printf((argc > 1) ? "%s " : "%s", *++argv);
	printf("\n");
	return 0;
}
