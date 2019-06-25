#include <stdio.h>
 
#define NMAX 111111
 
int x[NMAX], y[NMAX];
int N;
 
void ReadInput() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &x[i], &y[i]);
}
 
int SolveWith1() {
	int i, xmin = x[1], ymin = y[1], xmax = x[1], ymax = y[1];
	for (i = 2; i <= N; i++) {
		if (x[i] < xmin) xmin = x[i];
		if (x[i] > xmax) xmax = x[i];
		if (y[i] < ymin) ymin = y[i];
		if (y[i] > ymax) ymax = y[i];
	}
	for (i = 1; i <= N; i++) {
		if (x[i] == xmin && y[i] == ymin) {
			printf("1\n%d NE\n", i);
			return 1;
		}
		if (x[i] == xmin && y[i] == ymax) {
			printf("1\n%d SE\n", i);
			return 1;
		}
		if (x[i] == xmax && y[i] == ymin) {
			printf("1\n%d NW\n", i);
			return 1;
		}
		if (x[i] == xmax && y[i] == ymax) {
			printf("1\n%d SW\n", i);
			return 1;
		}
	}
	return 0;
}
 
void SolveWith2() {
	int i, idxmin = 1, idxmax = 1;
	for (i = 2; i <= N; i++) {
		if (x[i] < x[idxmin] || (x[i] == x[idxmin] && y[i] < y[idxmin])) idxmin = i;
		if (x[i] > x[idxmax] || (x[i] == x[idxmax] && y[i] > y[idxmax])) idxmax = i;
	}
	printf("2\n");
	if (y[idxmin] < y[idxmax]) {
		printf("%d NE\n%d SW\n", idxmin, idxmax);
	} else {
		printf("%d SE\n%d NW\n", idxmin, idxmax);
	}
}
 
int main() {
//	freopen("x.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		ReadInput();
		if (!SolveWith1()) SolveWith2();
	}
	return 0;
}
