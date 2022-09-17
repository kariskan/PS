#include <iostream>
#include <vector>
using namespace std;

int n, m, map[25][25];
long long ans;

bool can(int i, int j) {
	if (i >= 1 && j >= 1) {
		if (!(map[i - 1][j - 1] && map[i - 1][j] && map[i][j - 1]))return true;
		return false;
	}
	return true;
}

void go(int idx, int jdx) {

	ans++;

	for (int i = idx; i < n; i++) {
		for (int j = (i == idx ? jdx : 0); j < m; j++) {
			if (!map[i][j] && can(i, j)) {
				map[i][j] = 1;

				go(i, j + 1);

				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));

	go(0, 0);

	cout << ans;
}