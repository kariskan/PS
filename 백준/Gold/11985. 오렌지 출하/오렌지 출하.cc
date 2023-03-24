#include <iostream>
#include <climits>
using namespace std;

long long dp[20001];
long long n, m, k, a[20001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (long long i = 1; i <= n; i++)
	{
		dp[i] = LLONG_MAX;
		long long maxValue = a[i], minValue = a[i];
		for (int j = 0; j < m && i - j >= 1; j++)
		{
			minValue = min(minValue, a[i - j]);
			maxValue = max(maxValue, a[i - j]);

			dp[i] = min(dp[i], dp[i - j - 1] + k + (maxValue - minValue) * (j + 1));
		}
	}
	
	cout << dp[n];
}