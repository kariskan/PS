#include <iostream>
using namespace std;

int n, k, dp[101][100001];
pair<int, int> bike[101], walk[101];

int main()
{
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> bike[i].first >> bike[i].second >> walk[i].first >> walk[i].second;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i][j] = -2000000000;
			if (j >= bike[i].first )
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - bike[i].first] + bike[i].second);
			}
			if (j >= walk[i].first)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - walk[i].first] + walk[i].second);
			}
		}
	}

	cout << dp[n][k];
}