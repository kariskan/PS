#include <iostream>
using namespace std;

int n, map[1001][1001], dp[1001][1001][3];

int getM(int i, int j)
{
	return max(dp[i][j][0], max(dp[i][j][1], dp[i][j][2]));
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1000000000;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 0)
			{
				dp[i][j][0] = 1;
			}
			for (int k = 0; k <= 2; k++)
			{
				dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][k], dp[i][j - 1][k]));
				if (map[i][j] == k)
				{
					dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][(k - 1 + 3) % 3], dp[i][j - 1][(k - 1 + 3) % 3]) + 1);
				}
			}
		}
	}

	cout << (getM(n, n) < 0 ? 0 : getM(n, n));
}