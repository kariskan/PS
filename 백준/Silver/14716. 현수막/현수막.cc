#include <iostream>
using namespace std;
int n, m, map[250][250], visit[250][250];
int x[8] = { 0,0,1,-1,-1,-1,1,1 };
int y[8] = { 1,-1,0,0,-1,1,-1,1 };
void dfs(int i, int j) {
	for (int k = 0; k < 8; k++) {
		int nx = i + x[k];
		int ny = j + y[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny]) {
			visit[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] && !visit[i][j]) {
				ans++;
				dfs(i, j);
			}
		}
	}
	cout << ans;
}