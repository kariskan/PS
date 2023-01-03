#include <iostream>
using namespace std;
int n, m, r;
int map[300][300], ans[300][300];
int main()
{
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int line = min(min(i, j), min(n - i - 1, m - j - 1)); //껍데기 수
			int mod = (n - line * 2) * 2 + (m - line * 2) * 2 - 4;
			int rotate = r % mod; // 회전하는 횟수
			int x = i, y = j;

			while (rotate)
			{
				int cnt;
				if (x == line && y != line) // 위
				{
					cnt = min(rotate, y - line);
					rotate -= cnt;
					y -= cnt;
				}
				else if (y == line && x != n - line - 1) // 왼
				{
					cnt = min(rotate, n - line - 1 - x);
					rotate -= cnt;
					x += cnt;
				}
				else if (x == n - line - 1 && y != m - line - 1) // 아래
				{
					cnt = min(rotate, m - line - 1 - y);
					rotate -= cnt;
					y += cnt;
				}
				else // 오
				{
					cnt = min(rotate, x - line);
					rotate -= cnt;
					x -= cnt;
				}
			}

			ans[x][y] = map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}