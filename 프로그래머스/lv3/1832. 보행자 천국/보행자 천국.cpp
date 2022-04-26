#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int MOD = 20170805;
int dp[500][500];
queue<tuple<int, int, int>> q;
int solution(int m, int n, vector<vector<int>> city_map) {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (city_map[i][j] == 0 || city_map[i][j] == 2) {
				int idx = i - 1, jdx = j - 1;
				while (idx >= 0 && city_map[idx][j] == 2) {
					if (city_map[idx][j] == 1)break;
					idx--;
				}
				if (idx != -1 && city_map[idx][j] != 1) {
					dp[i][j] = (dp[i][j] % MOD + dp[idx][j] % MOD) % MOD;
				}
				while (jdx >= 0 && city_map[i][jdx] == 2) {
					if (city_map[i][jdx] == 1)break;
					jdx--;
				}
				if (jdx != -1 && city_map[i][jdx] != 1) {
					dp[i][j] = (dp[i][j] % MOD + dp[i][jdx] % MOD) % MOD;
				}
			}
			else {
				continue;
			}
		}
	}

	return dp[m - 1][n - 1] % MOD;
}