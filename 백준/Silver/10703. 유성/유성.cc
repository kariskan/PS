#include <iostream>
#include <queue>
using namespace std;

char map[3001][3001];
int comet[3001], earth[3001], diff[3001];
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	queue<pair<int, int>> q;
	cin >> n >> m;
	int minDiff = 987654321;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'X')
			{
				comet[j] = max(comet[j], i);
				map[i][j] = '.';
				q.push({i, j});
			}
			if (map[i][j] == '#')
			{
				if (earth[j] == 0 || earth[j] > i)
				{
					earth[j] = i;
				}
			}
			if (diff[j] == 0 || diff[j] > earth[j] - comet[j] - 1)
			{
				if (comet[j] != 0 && earth[j] != 0)
				{
					diff[j] = earth[j] - comet[j];
				}
			}
		}
	}
	for (int j = 1; j <= m; j++)
	{
		if (diff[j] != 0)
		{
			minDiff = min(minDiff, diff[j]);
		}
	}
	while (!q.empty())
	{
		map[q.front().first + minDiff - 1][q.front().second] = 'X';
		q.pop();
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}