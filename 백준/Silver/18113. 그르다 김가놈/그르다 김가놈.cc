#include <iostream>
using namespace std;

int a[1000000], n, k, m;

int main()
{
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int ans = -1;
	int left = 1, right = 1000000000;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] <= k)
			{
				continue;
			}
			if (a[i] >= 2 * k)
			{
				cnt += (a[i] - 2 * k) / mid;
			}
			else
			{
				cnt += (a[i] - k) / mid;
			}
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