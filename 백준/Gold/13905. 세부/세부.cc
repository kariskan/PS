#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> v;
vector<vector<pair<int, int>>> map;
int parent[100001];
int Find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
		return parent[x] = Find(parent[x]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	parent[a] = b;
}

int vis[100001];

void go(int node, int cost)
{
	for (auto &i : map[node])
	{
		int m = min(cost, i.second);
		if (vis[i.first] < m)
		{
			vis[i.first] = m;
			go(i.first, m);
		}
	}
}
bool compare(vector<int> &v1, vector<int> &v2)
{
	return v1[0] > v2[0];
}
int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	cin >> a >> b;
	map.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int c, d, e;
		cin >> c >> d >> e;
		vector<int> t = {e, c, d};
		v.push_back(t);
	}
	sort(v.begin(), v.end(), compare);
	for (auto &i : v)
	{
		if (Find(i[1]) != Find(i[2]))
		{
			Union(i[1], i[2]);
			map[i[1]].push_back({i[2], i[0]});
			map[i[2]].push_back({i[1], i[0]});
		}
	}
	vis[a] = 987654321;
	go(a, 987654321);

	cout << vis[b];
}