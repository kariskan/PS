#include <iostream>
using namespace std;

int map[301][301], n, m, k;
int dp[301][100001]; // dp[i][j] = i번째 도시에 j번째로 도착했을 때 최대 기내식

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = max(map[a][b], c);
	}
	
	dp[1][1] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (map[i][j])
			{
				for (int c = 1; c < m; c++)
				{
					if (dp[i][c])
					{
						dp[j][c + 1] = max(dp[j][c + 1], dp[i][c] + map[i][j]);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		ans = max(ans, dp[n][i]);
	}
	cout << (ans == 0 ? 0 : ans - 1);
}