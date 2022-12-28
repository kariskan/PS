#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<pair<int, int>>> v;
int vis[100001];
vector<int> e[100001];
vector<int> component[100001];
bool isLeaf[100001];
int leaf, componentIdx;

void findLeaf(int now)
{
	leaf = now;
	vis[now] = 1;
	for (auto &i : v[now])
	{
		if (!vis[i.first])
		{
			findLeaf(i.first);
		}
	}
}

void dfs(int now)
{
	component[componentIdx].push_back(now);
	vis[now] = 1;
	bool l = true;
	for (auto &i : v[now])
	{
		if (!vis[i.first])
		{
			e[componentIdx].push_back(i.second);
			l = false;
			dfs(i.first);
		}
	}
	isLeaf[now] = l;
}

void p(vector<int> g)
{
	for (auto &i : g)
	{
		cout << i << ' ';
	}
	cout << '\n';
}

int main()
{
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back({b, i + 1});
		v[b].push_back({a, i + 1});
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
			componentIdx++;
		}
	}
	if (componentIdx >= 3)
	{
		cout << -1;
		return 0;
	}
	if (componentIdx <= 1)
	{
		int a = 0, b = 0;
		for (int x : component[0])
		{
			if (isLeaf[x])
			{
				a = x;
			}
			else
			{
				b = x;
			}
		}

		component[0].clear();
		e[0].clear();
		memset(vis, 0, sizeof(vis));
		vis[a] = 1;
		componentIdx = 0;
		dfs(b);

		component[1].push_back(a);
	}

	if (component[0].size() == component[1].size())
	{
		cout << -1;
		return 0;
	}

	cout << component[0].size() << ' ' << component[1].size() << '\n';
	p(component[0]);
	p(e[0]);
	p(component[1]);
	p(e[1]);
}