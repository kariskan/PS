#include <iostream>
using namespace std;

int n, m, map[101][101];

int main() {
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 10000000;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (map[i][j] > 6) {
				cout << "Big World!";
				return 0;
			}
		}
	}

	cout << "Small World!";

	return 0;
}