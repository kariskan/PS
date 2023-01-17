#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, a[600];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);

	// 2, 3, 5, 5, 9
	int ans = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 3; j < n; j++)
		{
			int start = i + 1;
			int end = j - 1;

			int firstHeight = a[i] + a[j];

			while (start < end)
			{
				ans = min(ans, abs(firstHeight - a[start] - a[end]));
				if (a[start] + a[end] < firstHeight)
				{
					start++;
				}
				else
				{
					end--;
				}
			}
		}
	}

	cout << ans;
}