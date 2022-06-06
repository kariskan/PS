#include <iostream>
using namespace std;

int main() {
	int n, m, r;
	cin >> n >> m >> r;
	int item[101] = { 0, };
	int map[101][101] = { 0, };
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					map[i][j] = 0;
					continue;
				}
				if (map[i][k] && map[k][j])
					if (map[i][j] == 0 || map[i][j] > map[i][k] + map[k][j]) {
						map[i][j] = map[i][k] + map[k][j];
					}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (map[i][j] <= m) {
				if (i != j && map[i][j] == 0)continue;
				sum += item[j];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
}