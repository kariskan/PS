#include <iostream>
using namespace std;

int n;
int map[50][50];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			if (c == 'Y') {
				map[i][j] = 1;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				if (map[i][k] && map[k][j]) {
					if (map[i][j] == 0 || map[i][j] > map[i][k] + map[k][j]) {
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (map[i][j] <= 2 && map[i][j] != 0)cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}