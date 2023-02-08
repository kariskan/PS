#include <iostream>
using namespace std;
int a[1000000];
int main()
{
	long long n, m;
	long long left = 0, right = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		right = max(right, m * a[i]);
	}

	long long ans = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += mid / a[i];
		}

		if (cnt >= m)
		{
			right = mid - 1;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ans;
}