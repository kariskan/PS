#include <iostream>
using namespace std;
int map[500][500];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
pair<int, int> t[4][9] = {
	{{0,-2},{-1,-1},{1,-1},{-2,0},{-1,0},{1,0},{2,0},{-1,1},{1,1}},
};
int per[9] = { 5,10,10,2,7,7,2,1,1 };
int main() {
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 1) {
				t[i][j].first = -t[0][j].second;
				t[i][j].second = t[0][j].first;
			}
			else if (i == 2) {
				t[i][j].first = t[0][j].first;
				t[i][j].second = -t[0][j].second;
			}
			else {
				t[i][j].first = t[0][j].second;
				t[i][j].second = -t[0][j].first;
			}
		}
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int nx = (n + 1) / 2, ny = (n + 1) / 2;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 4; j++) {
			if (i % 2 != 0 && j >= 2)continue;
			if (i % 2 == 0 && j < 2)continue;
			for (int k = 0; k < i; k++) {
				nx += dx[j];
				ny += dy[j];
				if (map[nx][ny]) {
					int perSum = 0;
					for (int l = 0; l < 9; l++) {
						if (!(nx + t[j][l].first > 0 && nx + t[j][l].first <= n && ny + t[j][l].second > 0 && ny + t[j][l].second <= n)) {
							ans += map[nx][ny] * per[l] / 100;
						}	
						else {
							map[nx + t[j][l].first][ny + t[j][l].second] += map[nx][ny] * per[l] / 100;
						}
						perSum += map[nx][ny] * per[l] / 100;
					}
					if (nx + dx[j] > 0 && nx + dx[j] <= n && ny + dy[j] > 0 && ny + dy[j] <= n) {
						map[nx + dx[j]][ny + dy[j]] += map[nx][ny] - perSum;
					}
					else {
						ans += map[nx][ny] - perSum;
					}
					map[nx][ny] = 0;
				}
			}
		}
	}
	cout << ans;
}