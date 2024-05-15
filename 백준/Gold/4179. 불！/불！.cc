#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

int n, m, vis[1000][1000];
char board[1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

int main() {
	cin >> n >> m;

	queue<pair<int, int>> q, fire;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'J') {
				board[i][j] = '.';
				q.push({ i,j });
				vis[i][j] = 1;
			}
			if (board[i][j] == 'F') {
				fire.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int qSize = q.size();
		for (int k = 0; k < qSize; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (board[x][y] == 'F') {
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!range(nx, ny)) {
					cout << vis[x][y];
					return 0;
				}
				if (!vis[nx][ny] && board[nx][ny] != 'F' && board[nx][ny] != '#') {
					vis[nx][ny] = vis[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}

		qSize = fire.size();
		for (int k = 0; k < qSize; k++) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (range(nx, ny) && board[nx][ny] == '.') {
					board[nx][ny] = 'F';
					fire.push({ nx,ny });
				}
			}
		}
	}

	cout << "IMPOSSIBLE";
}