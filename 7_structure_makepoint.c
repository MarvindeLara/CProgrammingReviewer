/***************************************************************************
*	Author	: 	Marvin De Lara
*	FileName: 	7_structure_makepoint.c
*	Topic	: 	Structure
*	Task	: 	Structure
***************************************************************************/

#include <stdio.h>

#define XMAX 1000
#define YMAX 1000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
	int x;
	int y;
};
struct rect {
	struct point pt1;
	struct point pt2;
};

struct point make_point(int x, int y);
struct point add_point(struct point p1, struct point p2);
int ptinrect(struct point p, struct rect r);
struct rect canon_rect(struct rect r);

struct point make_point(int x, int y) {
	
	struct point temp;
	
	temp.x = x;
	temp.y = y;
	return temp;
}

struct point add_point(struct point p1, struct point p2) {

	p1.x = p1.x + p2.x;
	p1.y = p1.y + p2.y;
	return p1;
}

int ptinrect(struct point p, struct rect r) {

	return (p.x >= r.pt1.x) && (p.x <= r.pt2.x) && (p.y >= r.pt1.y) && (p.y <= r.pt2.y);
}

struct rect canon_rect(struct rect r) {

	struct rect temp;
	
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}

int main(int argc, char *argv[]) {
	
	struct rect screen;
	struct point middle;
	struct point new;
	
	screen.pt1 = make_point(XMAX, YMAX);
	screen.pt2 = make_point(0,0);
	middle = make_point((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);
	printf("LOW point of screen: x = %d, y = %d\n", screen.pt1.x, screen.pt1.y);
	printf("HIGH point of screen: x = %d, y = %d\n", screen.pt2.x, screen.pt2.y);
	printf("MIDDLE: x = %d, y = %d\n", middle.x, middle.y);
	if (ptinrect(middle, screen)) {
		printf("Point is in screen\n");
	} else {
		printf("Point is NOT in screen\n");
	}
	screen = canon_rect(screen);
	printf("LOW point of screen: x = %d, y = %d\n", screen.pt1.x, screen.pt1.y);
	printf("HIGH point of screen: x = %d, y = %d\n", screen.pt2.x, screen.pt2.y);
		if (ptinrect(middle, screen)) {
		printf("Point is in screen\n");
	} else {
		printf("Point is NOT in screen\n");
	}
	new = add_point(screen.pt2, middle);
	screen.pt2 = new;
	printf("LOW point of screen: x = %d, y = %d\n", screen.pt1.x, screen.pt1.y);
	printf("HIGH point of screen: x = %d, y = %d\n", screen.pt2.x, screen.pt2.y);
		if (ptinrect(middle, screen)) {
		printf("Point is in screen\n");
	} else {
		printf("Point is NOT in screen\n");
	}
	return 0;
}