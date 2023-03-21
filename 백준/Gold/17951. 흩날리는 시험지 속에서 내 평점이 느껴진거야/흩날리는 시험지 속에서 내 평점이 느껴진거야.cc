#include <iostream>
using namespace std;

int a[100000], n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int left = 20, right = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		left = min(left, a[i]);
		right += a[i];
	}
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int gc = 0, s = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > mid)
			{
				gc = 0;
				break;
			}
			s += a[i];
			if (s >= mid)
			{
				gc++;
				s = 0;
			}
		}
		

		if (s >= mid)
		{
			gc++;
		}

		if (gc >= m)
		{
			left = mid + 1;
			ans = max(ans, mid);
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;
}