#include <iostream>
using namespace std;

int n, m, dp[101][101][2][2]; // dp[i][j][0] = (i,j)에 동쪽으로 도달, dp[i][j][1] = (i,j)에 북쪽으로 도달, l = 1이면 방향 바꿈

int main()
{
	cin >> n >> m;
	dp[1][1][0][0] = dp[1][1][1][0] = dp[1][2][0][0] = dp[2][1][1][0] = 1;
	int mod = 100000;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && (j == 1 || j == 2))
			{
				continue;
			}
			if (i == 2 && j == 1)
			{
				continue;
			}

			dp[i][j][0][0] = (dp[i][j - 1][0][0] % mod + dp[i][j - 1][0][1] % mod) % mod;
			dp[i][j][0][1] = dp[i][j - 1][1][0];
			dp[i][j][1][0] += (dp[i - 1][j][1][0] % mod + dp[i - 1][j][1][1] % mod) % mod;
			dp[i][j][1][1] += dp[i - 1][j][0][0];
		}
	}

	cout << (dp[n][m][0][0] + dp[n][m][0][1] + dp[n][m][1][0] + dp[n][m][1][1]) % mod;
}