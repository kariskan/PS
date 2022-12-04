#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> p1, pair<int, string> p2)
{
		return p1.second < p2.second;
}

int main()
{
	int p, m;
	cin >> p >> m;
	vector<vector<pair<int, string>>> q;
	for (int i = 0; i < p; i++)
	{
		int a;
		string b;
		cin >> a >> b;
		// 입장 가능한 방이 있음
		int siz = q.size();
		int ok = 0;
		for (int j = 0; j < siz; j++)
		{
			vector<pair<int, string>> v = q[j];
			if (a >= v[0].first - 10 && a <= v[0].first + 10 && q[j].size() < m)
			{
				q[j].push_back({a, b});
				ok = 1;
				break;
			}
		}
		// 입장 가능한 방이 없음
		if (!ok)
		{
			vector<pair<int, string>> v;
			v.push_back({a, b});
			q.push_back(v);
		}
	}

	for (int i = 0; i < q.size(); i++)
	{
		if (q[i].size() == m)
		{
			cout << "Started!\n";
		}
		else
		{
			cout << "Waiting!\n";
		}
		sort(q[i].begin(), q[i].end(), compare);
		for (int j = 0; j < q[i].size(); j++)
		{
			cout << q[i][j].first << " " << q[i][j].second << '\n';
		}
	}
}