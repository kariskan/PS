#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m;

		int map[101][101] = { 0, };

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				map[i][j] = 987654321;
			}
		}

		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c;
			map[a][b] = map[b][a] = c;
		}

		for (int l = 1; l <= n; l++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i == j) continue;
					if (map[i][l] && map[l][j]) {
						map[i][j] = min(map[i][j], map[i][l] + map[l][j]);
					}
				}
			}
		}

		cin >> k;

		vector<int> v;

		for (int i = 0; i < k; i++) {
			int te; cin >> te;
			v.push_back(te);
		}

		int ans = -1, idx;

		for (int i = 1; i <= n; i++) {
			int temp = 0;
			for (int j = 0; j < v.size(); j++) {
				temp += map[v[j]][i];
			}
			if (ans == -1 || ans > temp) {
				ans = temp;
				idx = i;
			}
		}

		cout << idx << '\n';
	}
}