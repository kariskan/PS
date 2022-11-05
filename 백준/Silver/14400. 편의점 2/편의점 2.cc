#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

pair<int, int> a[100000];

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

int main()
{
	int n;
	cin >> n;
	long long left = 0, right = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	int x = a[n / 2].first;
	sort(a, a + n, compare);
	int y = a[n / 2].second;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += abs(x - a[i].first) + abs(y - a[i].second);
	}
	cout << ans;
}