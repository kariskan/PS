#include <iostream>
#include <set>
using namespace std;

long long dp[101][101];
int n, m, k;
set<pair<pair<int, int>, pair<int, int>>> se;
int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		swap(a, b);
		swap(c, d);
		se.insert({{a, b}, {c, d}});
		se.insert({{c, d}, {a, b}});
	}
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (i == 0)
			{
				if (!se.count({{i, j-1}, {i, j}}))
				{
					dp[i][j] = dp[i][j-1];
				}
			}
			else if (j == 0)
			{
				if (!se.count({{i-1, j}, {i, j}}))
				{
					dp[i][j] = dp[i-1][j];
				}
			}
			else
			{
				if (!se.count({{i, j - 1}, {i, j}}))
				{
					dp[i][j] += dp[i][j - 1];
				}
				if (!se.count({{i - 1, j}, {i, j}}))
				{
					dp[i][j] += dp[i - 1][j];
				}
			}
		}
	}

	cout << dp[n][m];
}