#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
char board[21][20];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int visit[10][20][20];
int starCnt = 0;
int curX, curY, sCount, stX, stY;
void bfs(int i, int j, int c) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visit[c][i][j] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[c][nx][ny] && board[nx][ny] != 'x') {
				visit[c][nx][ny] = visit[c][a][b] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0)break;
		sCount = 0, starCnt = 0;
		vector<pair<int, int>> v;
		int cnt[20][20];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				cnt[i][j] = -1;
				if (board[i][j] == 'o') {
					stX = i;
					stY = j;
				}
				if (board[i][j] == '*') {
					v.push_back({ i,j });
					cnt[i][j] = starCnt++;
				}
			}
		}
		int ans = 100000;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '*') {
					bfs(i, j, sCount);
					if (!visit[sCount][stX][stY]) {//답은 -1
						ans = -1;
					}
					sCount++;
				}
			}
		}
		if (ans == -1)cout << -1 << "\n";
		else {
			sort(v.begin(), v.end());
			do {
				int temp = 0;
				curX = stX;
				curY = stY;
				//visit[cnt[v[i].first][v[i].second][x][y]
				for (int i = 0; i < sCount; i++) {
					temp += visit[cnt[v[i].first][v[i].second]][curX][curY] - 1;
					curX = v[i].first;
					curY = v[i].second;
				}
				ans = min(ans, temp);
			} while (next_permutation(v.begin(), v.end()));
			cout << ans << "\n";
		}
		for (int i = 0; i < sCount; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					visit[i][j][k] = 0;
				}
			}
		}
	}
}