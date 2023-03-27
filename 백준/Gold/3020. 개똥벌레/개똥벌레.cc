#include <iostream>
using namespace std;

int n, m, top[500001], bottom[500001], tot[500001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (i % 2 == 0)
		{
			bottom[a]++;
		}
		else
		{
			top[a]++;
		}
	}

	for (int i = m - 1; i > 0; i--)
	{
		top[i] += top[i + 1];
		bottom[i] += bottom[i + 1];
	}

	int ans = 1000000000, cnt = 0;

	for (int i = 1; i <= m; i++)
	{
		tot[i] = bottom[i] + top[m - i + 1];
		if (ans >= tot[i])
		{
			if (ans == tot[i])
			{
				cnt++;
			}
			else
			{
				ans = tot[i];
				cnt = 1;
			}
		}
	}

	cout << ans << ' ' << cnt;
	return 0;
}