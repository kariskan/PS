#include <iostream>
#include <queue>
using namespace std;
int n, m;
char board[101][101];
int visit[101][101];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
pair<int, int> c1 = { -1,0 }, c2;
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'C') {
				if (c1.first == -1) {
					c1.first = i;
					c1.second = j;
				}
				else {
					c2.first = i;
					c2.second = j;
				}
			}
		}
	}
	queue<pair<int, int>> q; //i, j, dir
	q.push({ c1.first,c1.second });
	visit[c1.first][c1.second] = 1;
	int ans = 100000000;
	while (!q.empty()) {
		int a, b;
		a = q.front().first;
		b = q.front().second;
		q.pop();
		if (a == c2.first && b == c2.second) {
			ans = min(ans, visit[a][b]);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = a + x[i];
			int ny = b + y[i];
			while (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != '*') {
				if (!visit[nx][ny]) {
					visit[nx][ny] = visit[a][b] + 1;
					q.push({ nx,ny });
				}
				nx += x[i];
				ny += y[i];
			}
		}
	}
	cout << ans - 2;
}