#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int money[21] = {
			0,
		};
		for (int i = 1; i <= n; i++)
		{
			cin >> money[i];
		}
		int m;
		cin >> m;

		int dp[10001] = {
			1,
		};
		for (int i = 1; i <= n; i++)
		{
			for (int j = money[i]; j <= m; j++)
			{
				dp[j] += dp[j - money[i]];
			}
		}

		cout << dp[m] << '\n';
	}
}