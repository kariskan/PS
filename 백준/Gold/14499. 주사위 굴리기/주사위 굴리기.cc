#include <iostream>
using namespace std;

int n, m, x, y, k, map[20][20];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int dice[6]; // 0위 1앞 2왼 3오 4뒤 5아래

void up()
{
	int u = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[4];
	dice[4] = u;
}

void down()
{
	int u = dice[0];
	dice[0] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[1];
	dice[1] = u;
}

void left()
{
	int u = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[2];
	dice[2] = u;
}

void right()
{
	int u = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = u;
}

int main()
{
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		int com;
		cin >> com;
		int nx = x + dx[com];
		int ny = y + dy[com];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (com == 1)
			{
				right();
			}
			else if (com == 2)
			{
				left();
			}
			else if (com == 3)
			{
				up();
			}
			else
			{
				down();
			}
			if (map[nx][ny] == 0)
			{
				map[nx][ny] = dice[5];
			}
			else
			{
				dice[5] = map[nx][ny];
				map[nx][ny] = 0;
			}
			cout << dice[0] << '\n';

			x = nx;
			y = ny;
		}
	}
}