#include <iostream>
#include <climits>
using namespace std;
long long a[10000];
int main()
{
	long long n, m;
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
		for (int i = 0; i < n; i++)
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

	cout << ans;
}