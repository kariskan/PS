#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int n, m, cnt, board[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

bool bfs() {
	queue<pair<int, int>> q;
	int vis[100][100] = { 0, };

	q.push({ 0,0 });
	vis[0][0] = 1;

	queue <pair<int, int>> t;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (range(nx, ny) && !vis[nx][ny] && board[nx][ny] == 0) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
			if (range(nx, ny) && board[nx][ny] == 1) {
				t.push({ nx,ny });
			}
		}
	}

	while (!t.empty()) {
		int x = t.front().first;
		int y = t.front().second;
		t.pop();
		if (board[x][y] == 1) {
			cnt--;
		}
		board[x][y] = 0;
	}
	return cnt == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			cnt += board[i][j];
		}
	}

	int t = 0;
	while (1) {
		int preCnt = cnt;
		bfs();
		t++;
		if (cnt == 0) {
			cout << t << '\n' << preCnt;
			break;
		}
	}
}