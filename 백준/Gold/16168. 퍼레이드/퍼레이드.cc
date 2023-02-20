#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> v;
int vis[3001][3001];
int n, m;

void go(int node, int idx, int cnt)
{
	if (cnt == m)
	{
		cout << "YES";
		exit(0);
	}
	for (auto &i : v[node])
	{
		if (vis[i][node] != idx && vis[node][i] != idx)
		{
			vis[i][node] = vis[node][i] = idx;
			go(i, idx, cnt + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		go(i, i, 0);
	}

	cout << "NO";
}