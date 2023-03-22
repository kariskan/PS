#include <iostream>
#include <cstring>
using namespace std;

int map[1001][1001], dp[1001][1001], n, m;

int main()
{
	int n, m;
	while (cin >> n >> m, n != 0 && m != 0)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> map[i][j];
			}
		}
		
		int ans = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (map[i][j] == 0)
				{
					continue;
				}
				int len = min(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = map[i - len][j - len] == 1 ? len + 1 : len;
				ans = max(ans, dp[i][j]);
			}
		}
		
		cout << ans << '\n';

		memset(dp, 0, sizeof(dp));
	}
	
	
}