#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t, parent[10001];
vector<pair<int, pair<int, int>>> v;

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
	a = Find(a);
	b = Find(b);
	parent[a] = b;
}

int main()
{
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({c, {a, b}});
	}
	sort(v.begin(), v.end());
	int ans = 0, cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (Find(v[i].second.first) != Find(v[i].second.second))
		{
			Union(v[i].second.first, v[i].second.second);
			ans += v[i].first + t * cnt;
			cnt++;
		}
	}
	
	cout << ans;
}