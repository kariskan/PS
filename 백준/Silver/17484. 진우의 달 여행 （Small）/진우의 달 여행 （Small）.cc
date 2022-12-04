#include <cstring>
#include <iostream>
using namespace std;

// dp[i][j][k] = [i,j]에 k방향으로 도착했을 때 드는 연료의 최솟값

int main()
{
	int n, m;
	int map[7][8] = {
		0,
	};
	int dp[7][8][4] = {
		0,
	};
	memset(dp, 10000, sizeof(dp));
	cin >> n >> m;
	int ans = 987654321;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if (i == 1)
			{
				dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = map[i][j];
			}
			else
			{
				dp[i][j][1] = min(dp[i - 1][j + 1][2], dp[i - 1][j + 1][3]) + map[i][j];
				dp[i][j][2] = min(dp[i - 1][j][1], dp[i - 1][j][3]) + map[i][j];
				dp[i][j][3] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + map[i][j];
			}
			if (i == n)
			{
				ans = min(min(ans, dp[i][j][1]), min(dp[i][j][2], dp[i][j][3]));
			}
		}
	}
	cout << ans;
}