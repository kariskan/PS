#include <iostream>
#include <vector>
using namespace std;

int e[201], inp[1000001], p[201], n, m, dp[201][2];
vector<vector<int>> v;

int go(int node, int pre, int flag)
{
	if (dp[node][flag])
	{
		return dp[node][flag];
	}
	int res = (flag == 1 ? e[node] : 0);

	for (auto &i : v[node])
	{
		if (i != pre)
		{
			if (flag == 0)
			{
				res += max(go(i, node, 0), go(i, node, 1));
			}
			else
			{
				res += go(i, node, 0);
			}
		}
	}
	
	return dp[node][flag] = res;
}

int main()
{
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> e[i];
		inp[e[i]] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (e[i] + p[j] > 1000000 || inp[e[i] + p[j]] == 0)
			{
				continue;
			}
			v[i].push_back(inp[e[i] + p[j]]);
			v[inp[e[i] + p[j]]].push_back(i);
		}
	}

	cout << max(go(1, -1, 0), go(1, -1, 1));
}