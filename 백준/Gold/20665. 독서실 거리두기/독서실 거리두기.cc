#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, t, p;
int ti[101][1441];
pair<int, int> a[501];

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first)
	{
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

int getNumber(int now)
{
	int res = 0, maxL = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ti[i][now])
		{
			continue;
		}
		int minDis = 110;
		for (int j = 1; j <= n; j++)
		{
			if (j == i)
				continue;
			if (ti[j][now])
			{
				int dis = abs(j - i);
				minDis = min(minDis, dis);
			}
		}
		if (maxL < minDis)
		{
			maxL = minDis;
			res = i;
		}
	}

	return res;
}

int parseToMinute(string s)
{
	return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(2));
}

int main()
{
	cin >> n >> t >> p;

	for (int i = 1; i <= t; i++)
	{
		string start, end;
		cin >> start >> end;
		a[i] = {parseToMinute(start), parseToMinute(end)};
	}

	sort(a + 1, a + 1 + t, compare);

	for (int i = 1; i <= t; i++)
	{
		int start = a[i].first;
		int end = a[i].second;
		int num = getNumber(start);
		if (num != 0)
		{
			for (int j = start; j < end; j++)
			{
				ti[num][j] = i;
			}
		}
	}

	int ans = 0;

	for (int i = 9 * 60; i < 21 * 60; i++)
	{
		if (ti[p][i] == 0)
		{
			ans++;
		}
	}

	cout << ans;
}