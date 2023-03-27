#include <iostream>
using namespace std;

int n, dp[101][101];

int main()
{
	cin >> n;
	dp[1][0] = 2;
	int ans = 0, mod = 10007;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = ((dp[i - 1][j] * 2) % mod + dp[i - 1][j - 1] % mod + dp[i - 1][j + 1] % mod) % mod;
			if (i == n)
			{
				ans = (ans % mod + dp[i][j] % mod) % mod;
			}
		}
	}

	cout << ans;
}