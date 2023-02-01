#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int, int>> q;
int board[50][50];
vector<pair<int, int>> virus;
vector<int> t;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	t.resize(virus.size() - m);
	for (int i = 0; i < m; i++) {
		t.push_back(1);
	}
	int ans = -1;
	do {
		int visit[50][50] = { 0, };
		int res = 1;
		for (int i = 0; i < virus.size(); i++) {
			if (t[i] == 1) {
				q.push({ virus[i].first,virus[i].second });
				visit[virus[i].first][virus[i].second] = 1;
			}
		}
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = a + x[i];
				int ny = b + y[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && board[nx][ny] != 1) {
					visit[nx][ny] = visit[a][b] + 1;
					res = visit[nx][ny];
					q.push({ nx,ny });
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0 && board[i][j] != 1) {
					res = -1;
					break;
				}
			}
			if (res == -1)break;
		}
		if (ans == -1) {
			if (res != -1)ans = res - 1;
		}
		else {
			if (res != -1)ans = min(ans, res - 1);
		}
	} while (next_permutation(t.begin(), t.end()));
	cout << ans;
}