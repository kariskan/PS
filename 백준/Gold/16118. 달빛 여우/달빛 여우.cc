#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int n, m;
vector<vector<pair<int, long long>>> v;
vector<long long> dis1, dis2, dis3;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.resize(n + 1);
	dis1.resize(n + 1, LLONG_MAX);
	dis2.resize(n + 1, LLONG_MAX);
	dis3.resize(n + 1, LLONG_MAX);
	for (int i = 0; i < m; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c * 2});
		v[b].push_back({a, c * 2});
	}

	priority_queue<pair<long long, int>> pq;
	pq.push({0, 1});
	dis1[1] = 0;

	while (!pq.empty())
	{
		int node = pq.top().second;
		long long cost = -pq.top().first;
		pq.pop();

		if (dis1[node] < cost)
		{
			continue;
		}

		for (auto &i : v[node])
		{
			int nxNode = i.first;
			long long nxCost = cost + i.second;
			if (dis1[nxNode] > nxCost)
			{
				dis1[nxNode] = nxCost;
				pq.push({-nxCost, nxNode});
			}
		}
	}

	priority_queue<pair<long long, pair<int, int>>> pq2;
	pq2.push({0, {0, 1}});

	int first = 1;

	while (!pq2.empty())
	{
		int node = pq2.top().second.second;
		long long cost = -pq2.top().first;
		if (first)
		{
			cost = 0;
			first = 0;
		}
		int doubly = pq2.top().second.first;
		pq2.pop();

		for (auto &i : v[node])
		{
			int nxNode = i.first;
			int nxDoubly = 1 - doubly;
			long long nxCost = cost + (nxDoubly ? i.second / 2 : i.second * 2);
			if (nxDoubly)
			{
				if (dis3[nxNode] > nxCost)
				{
					pq2.push({-nxCost, {nxDoubly, nxNode}});
					dis3[nxNode] = nxCost;
				}
			}
			else
			{
				if (dis2[nxNode] > nxCost)
				{
					pq2.push({-nxCost, {nxDoubly, nxNode}});
					dis2[nxNode] = nxCost;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 2; i <= n; i++)
	{
		if (dis1[i] < dis2[i] && dis1[i] < dis3[i])
		{
			ans++;
		}
	}

	cout << ans;
}