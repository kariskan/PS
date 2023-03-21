#include <iostream>
using namespace std;

int dp[10001][250], c[10001], n, m;

int go(int k, int z)
{
	if (dp[k][z])
	{
		return dp[k][z];
	}
	if (k == n)
	{
		return 0;
	}

	int res = -1;

	for (int i = -1; i <= 1; i++)
	{
		if (z + i >= 1 && k + i + z <= n && !c[k + i + z])
		{
			int a = go(k + i + z, z + i);
			if ((res == -1 || res > a) && a != -1)
			{
				res = a + 1;
			}
		}
	}

	return dp[k][z] = res;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		c[a] = 1;
	}
	cout << go(1, 0);
}