#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> p[1000];

bool compare(pair<int, int> &p1, pair<int, int> &p2)
{
	if (p1.second == p2.second)
	{
		return p1.first > p2.first;
	}
	return p1.second > p2.second;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		p[i] = {b - a, b};
	}

	int ans = 10000000;
	sort(p, p + n, compare);
	for (int i = 1; i < n; i++)
	{
		if (p[i].second > p[i - 1].first)
		{
			int dif = abs(p[i].second - p[i - 1].first);
			p[i].first -= dif;
			p[i].second -= dif;
		}
		else
		{
			continue;
		}
	}

	if (p[n - 1].first < 0)
	{
		cout << -1;
	}
	else
	{
		cout << p[n - 1].first;
	}
}