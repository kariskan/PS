#include <stdio.h>
int a[100][100] = { 0, };
int ans = 0;
int bol = 0;
void dfs(int i, int j) {
	if (a[i][j] == 1) {
		bol = 1;
		a[i][j] = 0;
		if (a[i - 1][j] == 1 && i >= 1)dfs(i - 1, j);
		if (a[i][j - 1] == 1 && j >= 1)dfs(i, j - 1);
		if (a[i + 1][j] == 1)dfs(i + 1, j);
		if (a[i][j + 1] == 1)dfs(i, j + 1);
	}
	else return;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++) {
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			a[x][y] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				dfs(i, j);
				if (bol == 1)ans++;
				bol = 0;
			}
		}
		printf("%d\n", ans);
		ans = 0;
		bol = 0;
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++) {
				a[i][j] = 0;
			}
	}
}