#include <iostream>
using namespace std;
int map[1002][1002], dp[1002][1002];
// dp[i][j] = (i,j)를 왼쪽 위 꼭짓점으로 하는 가장 큰 정사각형의 한 변의 길이
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--)
		{
			// k = 인접한 오른쪽, 아래, 대각선 아래 방향의 가장 큰 정사각형의 한 변의 길이
			int k = min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
			if (map[i][j] == 0) // 현재 위치에서 정사각형을 그릴 수 있으면
			{
				dp[i][j] = k + 1;
			}
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;
}