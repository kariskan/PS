#include <iostream>
using namespace std;

int n, m, a[10001], dp[10001][502][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= min(i, m); j++)
		{
			if (j == 0)
			{
				dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]));
			}
			else
			{
				if (j < m)
				{
					dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
				}
				if (j == 1)
				{
					dp[i][j][1] = dp[i - 1][j - 1][0] + a[i];
				}
				dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][1] + a[i]);
			}
		}
	}

	cout << dp[n][0][0];
}