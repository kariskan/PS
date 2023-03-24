#include <iostream>
#include <set>
using namespace std;

int n, m, dp[20001];
int a[1001];
set<int> se;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		se.insert(a[i]);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i != j)
			{
				se.insert(a[i] + a[j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 10001;
	}

	for (auto &i : se)
	{
		for (int j = i; j <= n; j++)
		{
			dp[j] = min(dp[j], dp[j - i] + 1);
		}
	}

	cout << (dp[n] == 10001 ? -1 : dp[n]);
}