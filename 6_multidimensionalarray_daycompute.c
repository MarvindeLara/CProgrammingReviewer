/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	6_multidimensionalarray_daycompute.c
*	Topic	: 	Multidimensional arrays
*	Task	: 	Multidimensional arrays
***************************************************************************/

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int);

static char daytab[2][13] = {
							 {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
							 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
							};
							
int day_of_year(int year, int month, int day) {

	int i;
	int leap;
	
	leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	for (i = 1; i < month; i++) {
		day += daytab[leap][i];
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {

	int i;
	int leap;
	
	leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

char *month_name(int n) {

	static char *name[] = {
							"Illegal month", "January", "February",
							"March", "April", "May", "June", "July",
							"August", "September", "October",
							"November", "December"
						  };
	
	if (n < 1 || n > 12)
		return name[0];
	else
		return name[n];
}

int main(int argc, char *argv[]) {

	int month;
	int day;
	int *pmonth;
	int *pday;
	
	pmonth = &month;
	pday = &day;
	
	printf("Year of the day is: %d\n", day_of_year(2014, 8, 3));
	month_day(2014, day_of_year(2014, 8, 3), pmonth, pday);
	printf("Month-day is: %s %d\n", month_name(*pmonth), *pday);
	return 0;
}