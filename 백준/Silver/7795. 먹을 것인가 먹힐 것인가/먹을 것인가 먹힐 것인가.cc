#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int t, n, m, a[20000], b[20000];

int main()
{
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + m);

		int ans = 0;

		for (int i = 0; i < m; i++)
		{
			int l = n;
			int left = 0, right = n - 1;

			while (left <= right)
			{
				int mid = (left + right) / 2;

				if (a[mid] > b[i])
				{
					right = mid - 1;
					l = mid;
				}
				else
				{
					left = mid + 1;
				}
			}
			ans += n - l;
		}

		cout << ans << '\n';
	}
}