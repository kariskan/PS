#include <iostream>
#include <queue>
using namespace std;
int s[10];
char board[1001][1000];
int visit[1000][1000];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
queue<pair<int, int>> q[10];
queue<pair<int, int>> nq[10];
int ans[10];
int main() {
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k <= p; k++) {
				if (board[i][j] - '0' == k) {
					q[k].push({ i,j });
					visit[i][j] = 1;
					ans[k]++;
				}
			}
		}
	}
	while (1) {
		bool ok = false;
		for (int i = 1; i <= p; i++) {
			while (!q[i].empty()) {
				ok = true;
				int a, b;
				a = q[i].front().first;
				b = q[i].front().second;
				q[i].pop();
				for (int j = 0; j < 4; j++) {
					int nx = a + x[j];
					int ny = b + y[j];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == '.'&&!visit[nx][ny]) {
						visit[nx][ny] = visit[a][b] + 1;
						ans[i]++;
						if (visit[nx][ny] > s[i]) {
							visit[nx][ny] = 1;
							nq[i].push({ nx,ny });
						}
						else {
							q[i].push({ nx,ny });
						}
					}
				}
			}
			q[i] = nq[i];
			nq[i] = queue<pair<int, int>>();
		}
		if (!ok)break;
	}
	for (int i = 1; i <= p; i++) {
		cout << ans[i] << " ";
	}
}