#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, k, a[100000], sum[100000], sum2[100000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		memset(a, 0, sizeof(a));
		memset(sum2, 0, sizeof(sum2));
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i == 0)
			{
				sum[i] = a[i];
			}
			else
			{
				sum[i] += a[i] + sum[i - 1];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (i < m - 1)
			{
				sum2[i] = sum[i] + sum[n - 1] - sum[n - (m - i)];
			}
			else
			{
				sum2[i] = sum[i] - sum[i - m];
			}
			if (sum2[i] < k)
			{
				ans++;
			}
			if (n == m)
			{
				break;
			}
		}
		cout << ans << '\n';
	}
}