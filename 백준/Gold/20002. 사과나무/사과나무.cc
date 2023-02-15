#include <iostream>
#include <climits>
using namespace std;

int n, map[301][301], sum[301][301];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			sum[i][j] = map[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= min(i, j); k++)
			{
				ans = max(ans, sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k]);
			}
		}
	}
	
	cout << ans;
}