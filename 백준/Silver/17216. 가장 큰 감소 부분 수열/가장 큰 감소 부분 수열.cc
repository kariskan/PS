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
		dp[i] = max(dp[i], a[i]);
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				dp[j] = max(dp[j], dp[i] + a[j]);
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << ans;
}