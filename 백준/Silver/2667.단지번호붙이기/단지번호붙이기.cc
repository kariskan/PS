#include <stdio.h>
int n;
int ekswl = 0;
int apt[26][26] = { 0, };
int ans[26] = { 0, };
int x[5] = { 0,0,0,1,-1 };
int y[5] = { 0,1,-1,0,0 };
int house[26 * 26 / 2 + 1];
void DFS(int a, int b, int key) {
	apt[a][b] = key;
	int nextX, nextY;
	for (int i = 1; i <= 4; i++) {
		nextX = a + x[i];
		nextY = b + y[i];
		if (nextX >= 1 && nextY >= 1 && nextX <= n && nextY <= n) {
			if (apt[nextX][nextY] == 1)DFS(nextX, nextY, key);
		}
	}
}
void sol() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (apt[i][j] == 1) {
				ekswl++;
				DFS(i, j, ekswl + 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (apt[i][j]) {
				house[apt[i][j] - 1]++;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &apt[i][j]);
		}
	}
	sol();

	for (int i = 1; i <= ekswl; i++) {
		for (int j = 1; j <= ekswl - i; j++) {
			if (house[j] > house[j + 1]) {
				int temp = house[j];
				house[j] = house[j + 1];
				house[j + 1] = temp;
			}
		}
	}
	printf("%d\n", ekswl);
	for (int i = 1; i <= ekswl; i++) {
		printf("%d\n", house[i]);
	}
}