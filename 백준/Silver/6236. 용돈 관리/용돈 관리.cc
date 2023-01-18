#include <iostream>
using namespace std;
int a[100000];
int main()
{
	int n, m;
	cin >> n >> m;
	int start = 0, end = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		end += a[i];
	}

	int ans = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		int money = mid;
		int cnt = 1;
		for (int i = 0; i < n; i++)
		{
			if (money >= a[i])
			{
				money -= a[i];
			}
			else
			{
				money = mid;
				if (money < a[i])
				{
					cnt = 100001;
					break;
				}
				cnt++;
				money -= a[i];
			}
		}

		if (cnt > m)
		{
			start = mid + 1;
		}
		else
		{
			ans = mid;
			end = mid - 1;
		}
	}

	cout << ans;
}