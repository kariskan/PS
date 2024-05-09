#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

int n, m, board[501][501], dp[501][501];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool range(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int go(int x, int y) {
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	int res = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (range(nx, ny) && board[nx][ny] > board[x][y]) {
			int nxt = go(nx, ny);
			if (nxt != -1) {
				res += go(nx, ny);
			}
		}
	}
	return dp[x][y] = res;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}
	dp[1][1] = 1;
	cout << go(n, m);
}