#include <iostream>
#include <queue>
using namespace std;
int board[21][21];
int n, m;
int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
int ans;
void bfs() {
	queue<pair<int, int>>q;
	int visit[21][21] = { 0, };
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 2 && !visit[i][j]) {
				q.push({ i,j });
				visit[i][j] = 1;
				int brk = 0;
				int cnt = 1;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visit[nx][ny]) {
							if (board[nx][ny] == 0) {
								brk = 1;
							}
							else if (board[nx][ny] == 1)continue;
							else {
								q.push({ nx,ny });
								visit[nx][ny] = 1;
								cnt++;
							}
						}
					}
				}
				if (!brk) {
					sum += cnt;
				}
			}
		}
	}
	if (sum == 0)return;
	ans = max(ans, sum);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!board[i][j]) {
				board[i][j] = 1;
				for (int i1 = 1; i1 <= n; i1++) {
					for (int j1 = 1; j1 <= m; j1++) {
						if (!board[i1][j1]) {
							board[i1][j1] = 1;
							bfs();
							board[i1][j1] = 0;
						}
					}
				}
				board[i][j] = 0;
			}
		}
	}
	cout << ans;
}