#include <iostream>
using namespace std;

int n, m;
int qa, qb, map[401][401];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (map[i][k] && map[k][j]) {
					map[i][j] = 1;
				}
			}
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> qa >> qb;
		if (map[qa][qb]) {
			cout << "-1\n";
		}
		else if (map[qb][qa]) {
			cout << "1\n";
		}
		else cout << "0\n";
	}
}