#include <iostream>
#include <queue>
using namespace std;

int board[50][50], n, m;
int x[8] = { 0,-1,-1,-1,0,1,1,1 };
int y[8] = { 1,1,0,-1,-1,-1,0,1 };
int bfs(int i, int j) {
	queue<pair<int, int>> q;
	int visit[50][50] = { 0, };
	visit[i][j] = 1;
	q.push({ i,j });
	int res = 0;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]) {
				if (board[nx][ny] == 1) {
					res = visit[a][b] + 1;
					while (!q.empty())q.pop();
					return res - 1;
				}
				visit[nx][ny] = visit[a][b] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return res;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!board[i][j]) {
				int s = bfs(i, j);
				if (s) ans = max(s, ans);
			}
		}
	}
	cout << ans;
}