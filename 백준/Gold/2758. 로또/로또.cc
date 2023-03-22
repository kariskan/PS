#include <iostream>
#include <cmath>
using namespace std;

int t, n, m;
long long dp[11][2001];

int main()
{
	cin >> t;
	for (int i = 1; i <= 2000; i++)
	{
		dp[1][i] = i;
	}
	for (int i = 2; i <= 10; i++)
	{
		for (int j = pow(2, i - 1); j <= 2000; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j / 2];
		}
	}

	while (t--)
	{
		cin >> n >> m;
		cout << dp[n][m] << '\n';
	}
}