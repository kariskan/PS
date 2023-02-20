#include <iostream>
#include <algorithm>
using namespace std;

int shoot[100000];
pair<int, int> p[100000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, l;
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> shoot[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	sort(shoot, shoot + n);
	sort(p, p + m);

	int ans = 0;
	int idx = 0, pre = 0;

	for (int i = 0; i < n; i++)
	{
		int nowX = shoot[i];
		while (idx < m && abs(p[idx].first - nowX) + p[idx].second > l)
		{
			idx++;
		}
		pre = idx;
		while (idx < m && abs(p[idx].first - nowX) + p[idx].second <= l)
		{
			idx++;
		}

		ans += idx - pre;
		pre = idx;
	}

	cout << ans;
}