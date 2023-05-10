#include <stdio.h>
#include <stdlib.h>

int count1 = 0, count0 = 0;
void qnsgkf(int **a,int startx, int starty , int endx, int endy) {
	if ((endy == starty) && a[startx][starty] == 1) { count1++; return; }
	else if ((endy == starty) && a[startx][starty] == 0) { count0++; return; }
	int  b = 0;
	for (int i = startx; i <= endx; i++) {
		for (int j = starty; j <= endy; j++) {
			if (a[startx][starty] != a[i][j]) {
				b = 1; break;
			}
		}
		if (b == 1)break;
	}
	if (b == 0 && a[startx][starty] == 1)count1++;
	else if (b == 0 && a[startx][starty] == 0)count0++;
	else {
		qnsgkf(a, startx, starty, startx + (endx - startx) / 2, starty + (endy - starty) / 2);
		qnsgkf(a, startx, starty + (endy - starty) / 2 + 1, startx + (endx - startx) / 2, endy);
		qnsgkf(a, startx + (endx - startx) / 2 + 1, starty, endx, starty + (endy - starty) / 2);
		qnsgkf(a, startx + (endx - startx) / 2 + 1, starty + (endy - starty) / 2 + 1, endx, endy);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int** a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		a[i] = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	qnsgkf(a, 0, 0, n - 1, n - 1);
	printf("%d\n%d", count0, count1);
}