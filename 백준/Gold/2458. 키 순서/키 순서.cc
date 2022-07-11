#include <iostream>
using namespace std;
int map[501][501];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)map[i][j] = 1;
				else {
					if (map[i][k] && map[k][j]) {
						map[i][j] = 1;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int ok = 1;
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != 1 && map[j][i] != 1) {
				ok = 0;
				break;
			}
		}
		if (ok)ans++;
	}
	cout << ans;
}