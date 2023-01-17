#include <iostream>
#include <queue>
using namespace std;
char map[10][10];
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> q;
	int minx = 10, miny = 10, maxx = 0, maxy = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'X')
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + x[k];
					int ny = j + y[k];
					if (!(nx >= 0 && nx < n && ny >= 0 && ny < m) || map[nx][ny] == '.')
					{
						cnt++;
					}
				}
				if (cnt >= 3)
				{
					q.push({i, j});
				}
				else
				{
					minx = min(minx, i);
					miny = min(miny, j);
					maxx = max(maxx, i);
					maxy = max(maxy, j);
				}
			}
		}
	}
	while (!q.empty())
	{
		map[q.front().first][q.front().second] = '.';
		q.pop();
	}
	for (int i = minx; i <= maxx; i++)
	{
		for (int j = miny; j <= maxy; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}