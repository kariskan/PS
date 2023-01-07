#include <iostream>
#include <vector>
using namespace std;

int parent[1001];

int Find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	parent[Find(a)] = Find(b);
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({i + 1, {a, b}});
	}
	while (k--)
	{
		int ans = 0, cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
		}
		for (auto &i : v)
		{
			int cost = i.first;
			if (Find(i.second.first) != Find(i.second.second))
			{
				Union(i.second.first, i.second.second);
				ans += i.first;
				cnt++;
			}
		}
		if (cnt == n - 1)
		{
			cout << ans << ' ';
		}
		else
		{
			cout << 0 << ' ';
		}
		v.erase(v.begin());
	}
}