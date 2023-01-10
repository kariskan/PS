#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int n, m;
double limit;
pair<int, int> coor[1001];

double getDis(int a, int b)
{
	double x = coor[a].first - coor[b].first;
	double y = coor[a].second - coor[b].second;
	return sqrt(x * x + y * y);
}

int main()
{
	cin >> n >> m >> limit;
	vector<vector<pair<int, double>>> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> coor[i].first >> coor[i].second;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back({b, 0});
		v[b].push_back({a, 0});
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double dis = getDis(i, j);
			if (dis <= limit)
			{
				v[i].push_back({j, dis});
				v[j].push_back({i, dis});
			}
		}
	}
	vector<double> dis(n + 1, 5000000000);
	priority_queue<pair<double, int>> pq;

	dis[1] = 0;
	pq.push({0, 1});

	while (!pq.empty())
	{
		double cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dis[node] < cost)
			continue;

		for (auto &i : v[node])
		{
			int nxNode = i.first;
			double nxDis = cost + i.second;
			if (i.second <= limit && dis[nxNode] > nxDis)
			{
				dis[nxNode] = nxDis;
				pq.push({-nxDis, nxNode});
			}
		}
	}

	cout << (long long)(dis[n] * 1000);
}