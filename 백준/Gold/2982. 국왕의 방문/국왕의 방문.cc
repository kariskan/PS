#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, k, g;
pair<int, int> go[1001][1001];
vector<int> inp;
int v[1001][1001];

int main()
{
	cin >> n >> m >> a >> b >> k >> g;
	for (int i = 0; i < g; i++)
	{
		int in;
		cin >> in;
		inp.push_back(in);
	}
	for (int i = 0; i < m; i++)
	{
		int n1, n2, cost;
		cin >> n1 >> n2 >> cost;
		v[n1][n2] = cost;
		v[n2][n1] = cost;
	}
	int prev = 0;
	for (int i = 1; i < inp.size(); i++)
	{
		int n1 = inp[i - 1];
		int n2 = inp[i];
		go[n1][n2].first = prev;
		go[n2][n1].first = prev;
		go[n1][n2].second = prev + v[n1][n2];
		go[n2][n1].second = prev + v[n1][n2];
		prev += v[n1][n2];
	}

	vector<int> dis(n + 1, 987654321);
	priority_queue<pair<int, int>> pq;

	dis[a] = 0;
	pq.push({0, a});

	while (!pq.empty())
	{
		int node = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dis[node] < cost)
		{
			continue;
		}

		for (int i = 1; i <= n; i++)
		{
			if (i == node || !v[node][i])
			{
				continue;
			}
			int nxNode = i;
			int nxCost = cost;
			if (go[node][i].first - k <= nxCost && go[node][i].second - k >= nxCost)
			{
				nxCost = go[node][i].second - k;
			}
			nxCost += v[node][i];
			if (dis[nxNode] > nxCost)
			{
				dis[nxNode] = nxCost;
				pq.push({-nxCost, nxNode});
			}
		}
	}
	
	cout << dis[b];
}