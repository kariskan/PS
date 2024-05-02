#include <iostream>
using namespace std;

int map[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (map[a][b] <= c) {
			cout << "Enjoy other party\n";
		}
		else {
			cout << "Stay here\n";
		}
	}
}