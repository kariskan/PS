#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

bool compare(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2)
{
	return p1.second < p2.second;
}
int parent[250001];

int Find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	parent[a] = b;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c;
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				parent[i * c + j] = i * c + j;
			}
		}
		vector<pair<pair<int, int>, int>> v;
		for (int i = 0; i < r; i++)
		{
			for (int j = 1; j <= c - 1; j++)
			{
				int cost;
				cin >> cost;
				v.push_back({{i * c + j, i * c + j + 1}, cost});
			}
		}
		for (int i = 0; i < r - 1; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				int cost;
				cin >> cost;
				v.push_back({{i * c + j, (i + 1) * c + j}, cost});
			}
		}

		sort(v.begin(), v.end(), compare);

		int ans = 0;

		for (int i = 0; i < v.size(); i++)
		{
			int node1 = v[i].first.first;
			int node2 = v[i].first.second;
			int cost = v[i].second;

			if (Find(node1) != Find(node2))
			{
				Union(node1, node2);
				ans += cost;
			}
		}

		cout << ans << '\n';
	}
}