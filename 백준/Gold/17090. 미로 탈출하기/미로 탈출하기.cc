#include <iostream>
#include <cstring>
using namespace std;

int n, m;
char map[500][501];
int dp[500][500];
int visit[500][500];
int x[4] = { 0,0,1,-1 }; //RLDU
int y[4] = { 1,-1,0,0 };
string s = "RLDU";
int dfs(int i, int j) {
	visit[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		if (map[i][j] == s[k]) {
			int nx = i + x[k];
			int ny = j + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (dp[nx][ny] == -1) {
					if (!visit[nx][ny])dp[i][j] = dfs(nx, ny);
					else dp[i][j] = 0;
				}
				else dp[i][j] = dp[nx][ny];
			}
			else dp[i][j] = 1;
			break;
		}
	}
	return dp[i][j];
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j] == -1) {
				dfs(i, j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j])ans++;
		}
	}
	cout << ans;
}