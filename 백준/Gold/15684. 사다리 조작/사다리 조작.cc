#include <iostream>
using namespace std;
int board[32][12];
int n, m, h;
int ans = -1;
int run() {
	int brk = 0;
	for (int i = 1; i <= n; i++) {
		int x = 1;
		int y = i;
		while (1) {
			if (x == h + 1)break;
			if (board[x][y]) {
				x++;
				y++;
			}
			else if (board[x][y - 1]) {
				x++;
				y--;
			}
			else {
				x++;
			}
		}
		if (y != i) {
			brk = 1;
			break;
		}
	}
	if (brk)return 0;
	return 1;
}
void dfs(int pi, int pj, int cnt) {
	if (cnt > 3) {
		return;
	}
	if (run()) {
		if (ans == -1 || ans > cnt) {
			ans = cnt;
		}
	}
	for (int i = pi; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (i == pi && j <= pj)continue;
			if (!board[i][j - 1] && !board[i][j + 1] && !board[i][j]) {
				board[i][j] = 1;
				dfs(i, j, cnt + 1);
				board[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}
	dfs(1, 0, 0);
	cout << ans;
}