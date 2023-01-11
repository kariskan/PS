#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

long long n, m, a, b, c;
long long disC[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> a >> b >> c;
	vector<vector<pair<int, long long>>> v(n + 1);
	long long start = LLONG_MAX, end = 0;

	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		long long cost;
		cin >> n1 >> n2 >> cost;
		v[n1].push_back({n2, cost});
		v[n2].push_back({n1, cost});
		start = min(start, cost);
		end = max(end, cost);
	}

	long long ans = -1;

	while (start <= end)
	{
		long long mid = (start + end) / 2;
		memset(disC, -1, sizeof(disC));

		priority_queue<pair<int, int>> pq;
		pq.push({0, a});
		disC[a] = 0;

		while (!pq.empty())
		{
			int node = pq.top().second;
			long long cost = -pq.top().first;
			pq.pop();

			if (disC[node] < cost)
				continue;

			for (auto &i : v[node])
			{
				int nextNode = i.first;
				long long nextCost = i.second + cost;
				if (i.second > mid || nextCost > c || (disC[nextNode] <= nextCost))
				{
					continue;
				}
				pq.push({-nextCost, nextNode});
				disC[nextNode] = nextCost;
			}
		}

		if (disC[b] != -1)
		{
			ans = mid;
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	cout << ans;
}