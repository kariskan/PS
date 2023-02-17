#include <iostream>
#include <climits>
using namespace std;

int n, m, map[1001][1002], dp[1001][1002][3];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if (i == 1)
			{
				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = map[i][j];
			}
			else if (j == 1)
			{
				dp[i][j][2] = 1000000000;
			}
			else if (j == m)
			{
				dp[i][j][0] = 1000000000;
			}
		}
	}

	int ans = INT_MAX;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j != 1)
			{
				dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + map[i][j];
			}
			if (j != m)
			{
				dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + map[i][j];
			}
			dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + map[i][j];
			if (i == n)
			{
				ans = min(ans, dp[i][j][0]);
				ans = min(ans, dp[i][j][1]);
				ans = min(ans, dp[i][j][2]);
			}
		}
	}

	cout << ans;
}