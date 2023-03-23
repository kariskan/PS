#include <iostream>
using namespace std;

pair<int, int> inp[1001];
int dp[1001][16][16];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	for (int i = 1;; i++)
	{
		int a, b;
		cin >> a >> b;
		if (cin.eof())
		{
			break;
		}
		inp[i] = {a, b};
		n++;
	}
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		// 백을 골랐다.
		for (int j = 0; j <= 15; j++)
		{
			for (int k = 0; k <= 15; k++)
			{
				if (j == 0 && k == 0)
				{
					continue;
				}
				if (j > 0)
				{
					dp[i][j][k] = dp[i - 1][j - 1][k] + inp[i].first;
				}
				if (k > 0)
				{
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + inp[i].second);
				}
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
			}
		}
	}
	
	cout << dp[n][15][15];
}