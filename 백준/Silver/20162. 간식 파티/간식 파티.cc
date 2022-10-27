#include <iostream>
using namespace std;

int a[1000], dp[1000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i] = a[i];
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && dp[i] < dp[j] + a[i])
			{
				dp[i] = dp[j] + a[i];
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;
}