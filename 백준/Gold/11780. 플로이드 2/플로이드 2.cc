#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[101][101];
int route[101][101];

void go(int s, int e, vector<int>& ans) {
	if (route[s][e] == 0) {
		ans.push_back(s);
		ans.push_back(e);
		return;
	}
	go(s, route[s][e], ans);
	ans.pop_back();
	go(route[s][e], e, ans);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if(map[a][b] == 0 || map[a][b] > c) map[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (map[i][k] && map[k][j]) {
					if (map[i][j] == 0 || map[i][j] > map[i][k] + map[k][j]) {
						map[i][j] = map[i][k] + map[k][j];
						route[i][j] = k;
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || !map[i][j])cout << "0 ";
			else {
				vector<int> ans;
				go(i, j, ans);
				cout << ans.size() << ' ';
				for (auto& k : ans) {
					cout << k << ' ';
				}
			}
			cout << '\n';
		}
	}

}