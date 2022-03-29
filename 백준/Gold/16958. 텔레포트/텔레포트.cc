#include <iostream>
using namespace std;

int n, t, m;
pair<int, int> map[1001];
int special[1001];
int d[1001][1001];
int dis(int a, int b) {
	return abs(map[a].first - map[b].first) + abs(map[a].second - map[b].second);
}
int main() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		if (s)special[i] = 1;
		map[i].first = x;
		map[i].second = y;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			d[i][j] = dis(i, j);
			if (special[i] && special[j])d[i][j] = min(t, d[i][j]);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << d[a][b] << "\n";
	}
}