#include <iostream>
using namespace std;

int v, e;
int map[401][401];

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (i == j)continue;
				if (map[i][k] && map[k][j]) {
					if (map[i][j] == 0 || map[i][j] > map[i][k] + map[k][j]) {
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
	}
	int ans = -1;
	for (int i = 1; i <= v; i++) {
		for (int j = i + 1; j <= v; j++) {
			if (map[i][j] && map[j][i]) {
				if (ans == -1 || ans > map[i][j] + map[j][i]) {
					ans = map[i][j] + map[j][i];
				}
			}
		}
	}
	cout << ans;
}