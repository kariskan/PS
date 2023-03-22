#include <iostream>
#include <climits>
using namespace std;

int n, m, map[1001][1001], dp[1001][1001][2]; // 0 = 상승 1이면 하강

int main()
{
	cin >> n >> m;
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			dp[i][j][0] = dp[i][j][1] = INT_MIN;
		}
	}
	dp[0][1][0] = dp[0][1][1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[n - i + 1][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + map[i][j];
		}
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j][1] = max(dp[i][j][0], max(dp[i + 1][j][1], dp[i][j - 1][1])) + map[i][j];
		}
	}

	cout << dp[1][m][1];
}