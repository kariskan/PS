#include <iostream>
#include <queue>
using namespace std;
int x[4] = { 0,-1,0,1 };
int y[4] = { -1,0,1,0 };

int main() {
	int n, m;
	cin >> m >> n;
	int board[50][50] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int visit[50][50] = { 0, };
	int area[2501] = { 0, };
	int maxArea = 0;
	int cnt = 1;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				visit[i][j] = cnt;
				area[cnt]++;
				q.push({ i,j });
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x[k] + a;
						int ny = y[k] + b;
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && !(board[a][b] & (1 << k))) {
							visit[nx][ny] = visit[a][b];
							area[cnt]++;
							q.push({ nx,ny });
						}
					}
				}
				maxArea = max(maxArea, area[cnt]);
				cnt++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + x[k];
				int ny = j + y[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && visit[i][j] != visit[nx][ny]) {
					ans = max(ans, area[visit[i][j]] + area[visit[nx][ny]]);
				}
			}
		}
	}

	cout << cnt - 1 << "\n" << maxArea <<"\n"<< ans << "\n";
}