#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, m, c, dp[100][100][81];
char map[100][100];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
string t;

int go(int i, int j, int l) {
	
	if (l == t.length())return 1;
	if (dp[i][j][l] != -1)return dp[i][j][l];

	int ret = 0;

	for (int k = 0; k < 4; k++) {
		for (int cnt = 1; cnt <= c; cnt++) {
			int nx = i + x[k] * cnt;
			int ny = j + y[k] * cnt;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == t[l]) {
				ret += go(nx, ny, l + 1);
			}
		}
	}

	return dp[i][j][l] = ret;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cin >> t;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (t[0] == map[i][j]) {
				ans += go(i, j, 1);
			}
		}
	}

	cout << ans;
	return 0;
}