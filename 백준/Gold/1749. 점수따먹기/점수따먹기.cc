#include <iostream>
#include <climits>
using namespace std;

int n, m, a[201][201], s[201][201];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			s[i][j] = a[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
		}
	}
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int i1 = 0; i1 < i; i1++)
			{
				for (int j1 = 0; j1 < j; j1++)
				{
					ans = max(ans, s[i][j] - s[i1][j] - s[i][j1] + s[i1][j1]);
				}
			}
		}
	}

	cout << ans;
}