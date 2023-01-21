#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, ok;
vector<vector<pair<int, int>>> v;
int parent[1001];

int dijk(int a, int b)
{
	vector<int> dis(n + 1, 987654321);
	priority_queue<pair<int, int>> pq;

	dis[1] = 0;
	pq.push({0, 1});

	while (!pq.empty())
	{
		int node = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dis[node] < cost)
			continue;

		for (auto &i : v[node])
		{
			if (ok && ((node == a && i.first == b) || (node == b && i.first == a)))
			{
				continue;
			}
			int nxNode = i.first;
			int nxCost = cost + i.second;
			if (dis[nxNode] > nxCost)
			{
				if (!ok)
				{
					parent[nxNode] = node;
				}
				pq.push({-nxCost, nxNode});
				dis[nxNode] = nxCost;
			}
		}
	}

	ok = 1;

	if (dis[n] == 987654321)
	{
		return -1;
	}

	return dis[n];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	int dis = dijk(-1, -1);
	int ans = -1;
	for (int i = n; i != parent[i]; i = parent[i])
	{
		int t = dijk(i, parent[i]);
		if (t == -1)
		{
			ans = -1;
			break;
		}
		ans = max(ans, t - dis);
	}

	cout << ans;
}
