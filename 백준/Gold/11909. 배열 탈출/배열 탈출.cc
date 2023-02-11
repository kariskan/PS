#include <iostream>
using namespace std;

int n, map[2222][2222], dp[2222][2222];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 & j == 0)
			{
				continue;
			}
			if (i == 0)
			{
				dp[i][j] = dp[i][j - 1] + max(0, map[i][j] + 1 - map[i][j - 1]);
			}
			else if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + max(0, map[i][j] + 1 - map[i - 1][j]);
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j] + max(0, map[i][j] + 1 - map[i - 1][j]), dp[i][j - 1] + max(0, map[i][j] + 1 - map[i][j - 1]));
			}
		}
	}
	
	cout << dp[n - 1][n - 1];
}