#include <iostream>
using namespace std;

int n, m, dp[10001];
pair<int, int> p[1001];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = n; j >= p[i].second; j--)
		{
			dp[j] = max(dp[j], dp[j - p[i].second] + p[i].first);
		}
	}

	cout << dp[n];
}