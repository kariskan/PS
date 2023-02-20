#include <iostream>
using namespace std;

long long dp[1000001], sum[1000001];

int main()
{
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 7;
	dp[3] = 22;
	sum[1] = 3;
	sum[2] = 10;
	sum[3] = 32;

	long long mod = 1000000007;

	for (int i = 4; i <= n; i++)
	{
		dp[i] = (dp[i - 1] * 2 % mod + dp[i - 2] * 3 % mod + sum[i - 3] * 2 % mod) % mod;
		sum[i] = (sum[i - 1] % mod + dp[i] % mod) % mod;
	}

	cout << dp[n];
}