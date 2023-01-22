#include <iostream>
using namespace std;
long long a[1000000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	long long left = 1, right = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		right = max(right, a[i]);
	}
	long long ans = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < m; i++)
		{
			cnt += a[i] / mid;
		}
		if (cnt >= m)
		{
			left = mid + 1;
			ans = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	
	cout << sum - ans * m;
}