#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

pair<long long, long long> coor[1500];

int main()
{

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> coor[i].first >> coor[i].second;
	}
	sort(coor, coor + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		map<pair<long long, long long>, int> m;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			long long x = coor[i].first - coor[j].first;
			long long y = coor[i].second - coor[j].second;
			long long g = gcd(x, y);
			if (g < 0)
				g = -g;
			x /= g, y /= g;
			m[{x, y}]++;
		}
		for (auto &j : m)
		{
			int nowX = j.first.first;
			int nowY = j.first.second;
			if (m.count({-nowY, nowX}))
			{
				ans += j.second * m[{-nowY, nowX}];
			}
		}
	}
	cout << ans;
}