#include <iostream>
using namespace std;

int n, m, a[300000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int left = 1, right = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		right = max(right, a[i]);
	}

	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			if (a[i] % mid == 0)
			{
				cnt += a[i] / mid;
			}
			else
			{
				cnt += a[i] / mid + 1;
			}
		}

		if (cnt <= n)
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