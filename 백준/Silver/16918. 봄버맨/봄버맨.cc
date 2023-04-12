#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k;
int map[200][200];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a; cin >> a;
			if (a == 'O') {
				map[i][j] = 1;
			}
			else {
				continue;
			}
		}
	}
	for (int t = 0; t < k; t++) {
		if (t == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[i][j])map[i][j]++;
				}
			}
			continue;
		}
		if (t % 2 == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					map[i][j]++;
				}
			}
		}
		else {
			int copyMap[200][200] = { 0, };
			copy(&map[0][0], &map[0][0] + 40000, &copyMap[0][0]);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[i][j] >= 3) {
						copyMap[i][j] = 0;
						for (int l = 0; l < 4; l++) {
							int nx = x[l] + i;
							int ny = y[l] + j;
							if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
								copyMap[nx][ny] = 0;
							}
						}
					}
					else if (copyMap[i][j])copyMap[i][j]++;
				}
			}
			copy(&copyMap[0][0], &copyMap[0][0] + 40000, &map[0][0]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j])cout << 'O';
			else cout << '.';
		}
		cout << "\n";
	}
}