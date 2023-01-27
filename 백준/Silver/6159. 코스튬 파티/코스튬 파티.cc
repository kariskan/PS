#include <iostream>
#include <algorithm>
using namespace std;

int n, s;	  // n:소의 개수, s: 코스튬 사이즈
int a[20001]; // 소의 사이즈

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int left = i + 1, right = n - 1;
		int cnt = -1;
		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (a[mid] + a[i] > s)
			{
				right = mid - 1;
			}
			else
			{
				cnt = mid;
				left = mid + 1;
			}
		}

		if (cnt != -1)
		{
			ans += cnt - i;
		}
	}
	
	cout << ans;
}