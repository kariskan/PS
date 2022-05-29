#include <stdio.h>

int map[1002][3] = { 0, };
int dpR[1002][3] = { 0, };
int dpG[1002][3] = { 0, };
int dpB[1002][3] = { 0, };

int min(int a, int b) {
	if (a < b)return a;
	return b;
}
char RGB(int n) {
	if (n == 0)return 'R';
	if (n == 1)return 'G';
	return 'B';
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &map[i][j]);

	dpR[1][0] = map[1][0];
	dpG[1][1] = map[1][1];
	dpB[1][2] = map[1][2];

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 2) {
				if (j == 0)dpR[i][j] = 1000001;
				else
				dpR[i][j] = map[i][j] + dpR[i - 1][0];
			}
			else if (i < n) {
				if (j == 0) {
					dpR[i][j] = map[i][j] + min(dpR[i - 1][1], dpR[i - 1][2]);
				}
				else if (j == 1) {
					dpR[i][j] = map[i][j] + min(dpR[i - 1][0], dpR[i - 1][2]);
				}
				else {
					dpR[i][j] = map[i][j] + min(dpR[i - 1][0], dpR[i - 1][1]);
				}
			}
			else {
				if (j == 0)dpR[i][j] = 1000001;
				else if (j == 1) {
					dpR[i][j] = map[i][j] + min(dpR[i - 1][0], dpR[i - 1][2]);
				}
				else {
					dpR[i][j] = map[i][j] + min(dpR[i - 1][0], dpR[i - 1][1]);
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 2) {
				if (j == 1)dpG[i][j] = 1000001;
				else
					dpG[i][j] = map[i][j] + dpG[i - 1][1];
			}
			else if (i < n) {
				if (j == 0) {
					dpG[i][j] = map[i][j] + min(dpG[i - 1][1], dpG[i - 1][2]);
				}
				else if (j == 1) {
					dpG[i][j] = map[i][j] + min(dpG[i - 1][0], dpG[i - 1][2]);
				}
				else {
					dpG[i][j] = map[i][j] + min(dpG[i - 1][0], dpG[i - 1][1]);
				}
			}
			else {
				if (j == 1)dpG[i][j] = 1000001;
				else if (j == 0) {
					dpG[i][j] = map[i][j] + min(dpG[i - 1][1], dpG[i - 1][2]);
				}
				else {
					dpG[i][j] = map[i][j] + min(dpG[i - 1][0], dpG[i - 1][1]);
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 2) {
				if (j == 2)dpB[i][j] = 1000001;
				else
					dpB[i][j] = map[i][j] + dpB[i - 1][2];
			}
			else if (i < n) {
				if (j == 0) {
					dpB[i][j] = map[i][j] + min(dpB[i - 1][1], dpB[i - 1][2]);
				}
				else if (j == 1) {
					dpB[i][j] = map[i][j] + min(dpB[i - 1][0], dpB[i - 1][2]);
				}
				else {
					dpB[i][j] = map[i][j] + min(dpB[i - 1][0], dpB[i - 1][1]);
				}
			}
			else {
				if (j == 2)dpB[i][j] = 1000001;
				else if (j == 1) {
					dpB[i][j] = map[i][j] + min(dpB[i - 1][0], dpB[i - 1][2]);
				}
				else {
					dpB[i][j] = map[i][j] + min(dpB[i - 1][1], dpB[i - 1][2]);
				}
			}
		}
	}
	int ans = min(min(dpR[n][0], dpR[n][1]), dpR[n][2]);
	if (ans > min(min(dpG[n][0], dpG[n][1]), dpG[n][2]))ans = min(min(dpG[n][0], dpG[n][1]), dpG[n][2]);
	if (ans > min(min(dpB[n][0], dpB[n][1]), dpB[n][2]))ans = min(min(dpB[n][0], dpB[n][1]), dpB[n][2]);
	printf("%d", ans);
}