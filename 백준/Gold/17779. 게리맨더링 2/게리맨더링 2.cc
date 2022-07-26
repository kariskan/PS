#include <iostream>
#include <cstring>
using namespace std;

int n;
int map[21][21], p[6], gu[21][21];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

int get() {
	int max = -1, min = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			p[gu[i][j]] += map[i][j];
		}
	}
	for (int i = 1; i <= 5; i++) {
		if (max == -1 || max < p[i])max = p[i];
		if (min == -1 || min > p[i])min = p[i];
	}
	return max - min;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 10000000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (!(i + d1 + d2 <= n && j - d1 >= 1 && j + d2 <= n))continue;
					memset(p, 0, sizeof(p));
					memset(gu, 0, sizeof(gu));
					for (int i1 = 0; i1 <= d1; i1++) {
						gu[i + i1][j - i1] = gu[i + d2 + i1][j + d2 - i1] = 5;
					}
					for (int i1 = 0; i1 <= d2; i1++) {
						gu[i + i1][j + i1] = gu[i + d1 + i1][j - d1 + i1] = 5;
					}
					for (int i1 = 1; i1 <= n; i1++) {
						int cnt5 = 0, f = 0, s = 0;
						for (int j1 = 1; j1 <= n; j1++) {
							if (gu[i1][j1] == 5) {
								cnt5++;
								if (f == 0)f = j1;
								else s = j1;
							}
						}
						if (cnt5 == 2) {
							for (int k = f; k <= s; k++)gu[i1][k] = 5;
						}
					}

					for (int i1 = 1; i1 <= n; i1++) {
						for (int j1 = 1; j1 <= n; j1++) {
							if (gu[i1][j1])continue;
							if (i1 < i + d1 && j1 <= j) { //1
								gu[i1][j1] = 1;
							}
							else if (i1 <= i + d2 && j1 > j) {
								gu[i1][j1] = 2;
							}
							else if (i1 >= i + d1 && j1 < j - d1 + d2) {
								gu[i1][j1] = 3;
							}
							else if (i1 > i + d2 && j1 >= j - d1 + d2) {
								gu[i1][j1] = 4;
							}
							if (gu[i1][j1] == 0) {
								gu[i1][j1] = 5;
							}
						}
					}
					ans = min(ans, get());
				}
			}
		}
	}

	cout << ans;
}