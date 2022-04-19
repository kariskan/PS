#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	vector<vector<int>> board(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 100000000));
	for (int i = 0; i < m; i++) {
		board[edge_list[i][0]].push_back(edge_list[i][1]);
		board[edge_list[i][1]].push_back(edge_list[i][0]);
	}


	dp[0][gps_log[0]] = 0;

	for (int i = 1; i < k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j]);
			for (int b : board[j]) {
				dp[i][j] = min(dp[i - 1][b], dp[i][j]);
			}
			if (gps_log[i] != j)dp[i][j] += 1;
		}
	}

	if (dp[k - 1][gps_log[k - 1]] < 100000000)return dp[k - 1][gps_log[k - 1]];
	else return -1;
}