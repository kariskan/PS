#include <iostream>
using namespace std;
int map[101][101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (map[a][b] == 0 || map[a][b] > c)map[a][b] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0)map[i][j] = -1;
			if (i == j)map[i][j] = 0;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] != -1 && map[k][j] != -1) {
					if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j])
						map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == -1)cout << 0 << " ";
			else cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}