#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100001];
map<int, int> ma;

bool compare(pair<int, int> &p1, pair<int, int> &p2)
{
	return p1.second > p2.second;
}

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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a = Find(a);
		b = Find(b);
		if (a != b)
		{
			Union(a, b);
		}
	}

	int c, h, k;
	cin >> c >> h >> k;
	int han = Find(h);
	for (int i = 1; i <= n; i++)
	{
		int t = Find(i);
		if (han != t)
		{
			ma[t]++;
		}
	}
	int ans = ma[Find(c)];

	vector<pair<int, int>> v;
	for (auto &i : ma)
	{
		v.push_back({i.first, i.second});
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size() && k; i++, k--)
	{
		ans += v[i].second;
	}
	cout << ans;
}