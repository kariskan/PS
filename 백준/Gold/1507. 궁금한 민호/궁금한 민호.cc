#include <iostream>
using namespace std;

int n;
int map[20][20];
bool check() {
	int temp[20][20] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = map[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (i == j)continue;
				if (map[i][k] && map[k][j]) {
					if (temp[i][j] == 0 || temp[i][j] > map[i][k] + map[k][j]) {
						temp[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != temp[i][j])return false;
		}
	}
	return true;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	if (check()) {
		int ans = 0;
		for (int i1 = 0; i1 < n; i1++) {
			for (int j1 = i1 + 1; j1 < n; j1++) {
				int num = map[i1][j1];
				int temp[20][20] = { 0, };
				map[i1][j1] = 0;

				for (int k = 0; k < n; k++) {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {

							if (i == j)continue;
							if (map[i][k] && map[k][j]) {
								if (temp[i][j] == 0 || temp[i][j] > map[i][k] + map[k][j]) {
									temp[i][j] = map[i][k] + map[k][j];
								}
							}
						}
					}
				}
				if (temp[i1][j1] != num) ans += num;
				map[i1][j1] = num;
			}
		}
		cout << ans;
	}
	else cout << -1;
}