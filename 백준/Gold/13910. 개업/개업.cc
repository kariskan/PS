#include <iostream>
#include <vector>
using namespace std;

int n, m, dp[20001];
vector<int> v;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j)
			{
				continue;
			}
			v.push_back(v[i] + v[j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 10001;
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = v[i]; j <= n; j++)
		{
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
		}
	}

	cout << (dp[n] == 10001 ? -1 : dp[n]);
}