#include <iostream>
using namespace std;
int a[1001];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int b;
		cin >> b;
		a[b] = 1;
	}
	int ans = 2000000000;
	for (int i = 1; i <= 1001; i++)
	{
		for (int j = i; j <= 1001; j++)
		{
			for (int k = j; k <= 1001; k++)
			{
				if (a[i] || a[j] || a[k])
				{
					continue;
				}
				ans = min(ans, abs(n - i * j * k));
			}
		}
	}

	cout << ans;
}