#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int n, t;
map<pair<int, int>, vector<pair<int, int>>> m;
map<pair<int, int>, int> vis;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> t;
	m[{0, 0}] = {};
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		m[{a, b}] = {};
		for (int j = a - 2; j <= a + 2; j++)
		{
			for (int k = b - 2; k <= b + 2; k++)
			{
				if (a == j && k == b)
				{
					continue;
				}
				if (m.count({j, k}))
				{
					m[{j, k}].push_back({a, b});
					m[{a, b}].push_back({j, k});
				}
			}
		}
	}

	queue<pair<int, int>> q;
	vis[{0, 0}] = 1;
	q.push({0, 0});

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (b == t)
		{
			cout << vis[{a, b}] - 1;
			return 0;
		}

		for (auto &i : m[{a, b}])
		{
			if (!vis.count({i.first, i.second}))
			{
				vis[{i.first, i.second}] = vis[{a, b}] + 1;
				q.push({i.first, i.second});
			}
		}
	}

	cout << -1;
}