#include <iostream>
using namespace std;

int n, m, a, b, map[101][101];
pair<int, int> dp[101][101];

int main()
{
	cin >> n >> m >> a >> b;
	for (int i = 0; i < a; i++)
	{
		int A, B;
		cin >> A >> B;
		map[A][B] = 1;
	}
	for (int i = 0; i < b; i++)
	{
		int A, B;
		cin >> A >> B;
		map[A][B] = 2;
	}
	dp[1][1] = {1, map[1][1] == 1 ? 1 : 0};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1)
			{
				continue;
			}
			if (map[i][j] == 2)
			{
				continue;
			}
			if (dp[i - 1][j].second > dp[i][j - 1].second)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else if (dp[i - 1][j].second < dp[i][j - 1].second)
			{
				dp[i][j] = dp[i][j - 1];
			}
			else
			{
				dp[i][j] = {dp[i][j - 1].first + dp[i - 1][j].first, dp[i][j - 1].second};
			}
			if (map[i][j] == 1)
			{
				dp[i][j].second++;
			}
		}
	}

	cout << (dp[n][m].second == a ? dp[n][m].first : 0);
}