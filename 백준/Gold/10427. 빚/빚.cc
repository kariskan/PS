#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n, a[4001], ma[4001], sum[4001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		memset(a, sizeof(a), 0);
		memset(ma, sizeof(ma), 0);
		memset(sum, sizeof(sum), 0);

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			ma[i] = max(a[i], ma[i - 1]);
			sum[i] = a[i] + sum[i - 1];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			long long t = -1;
			for (int j = i; j <= n; j++)
			{
				if (t == -1 || t > a[j] * i - (sum[j] - sum[j - i]))
				{
					t = a[j] * i - (sum[j] - sum[j - i]);
				}
			}
			ans += t;
		}

		cout << ans << '\n';
	}
}