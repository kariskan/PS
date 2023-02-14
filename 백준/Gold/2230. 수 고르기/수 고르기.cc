#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[100000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	int ans = -1;

	for (int i = 0; i < n; i++)
	{
		int left = i + 1, right = n - 1;
		int temp = -1;
		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (a[mid] - a[i] >= m)
			{
				temp = a[mid] - a[i];
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		if (ans == -1 || (ans > temp && temp != -1))
		{
			ans = temp;
		}
	}

	cout << ans;
}