#include <iostream>
using namespace std;
int x[3] = { -1,0,1 };
int y[3] = { 1,1,1 };
int n, m;
int map[10000][500], visit[10000][500];
bool check = false;
int ans;
void go(int i, int j) {
	visit[i][j] = 1;
	if (j == m - 1) {
		check = true;
		ans++;
		return;
	}
	for (int k = 0; k < 3; k++) {
		int nx = i + x[k];
		int ny = j + y[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 1 && !visit[nx][ny]) {
			go(nx, ny);
			if (check)return;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (c == '.')map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		check = false;
		go(i, 0);
	}

	cout << ans;
}