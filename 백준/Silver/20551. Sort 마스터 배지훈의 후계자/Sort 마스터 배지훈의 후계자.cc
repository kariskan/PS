#include <iostream>
#include <algorithm>
using namespace std;
int a[200000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		int start = 0, end = n - 1;
		int ans = -1;
		while (start <= end)
		{
			int mid = (start + end) / 2;

			if (a[mid] >= k)
			{
				if ((a[mid] == k) && ans == -1 || ans > mid)
				{
					ans = mid;
				}
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		cout << ans << "\n";
	}
}