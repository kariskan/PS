#include <iostream>
using namespace std;

int dp[101][301][301], n, a, b;
pair<int, int> inp[101];

int main()
{
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> inp[i].first >> inp[i].second;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = a; j >= 1; j--)
		{
			for (int k = b; k >= 1; k--)
			{
				if (j - inp[i].first >= 0 && k - inp[i].second >= 0)
				{
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - inp[i].first][k - inp[i].second] + 1);
				}
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
			}
		}
	}

	cout << dp[n][a][b];
}