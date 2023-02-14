#include <iostream>
using namespace std;

int n, m, check[1000][1000];
char a[1000][1000];
int ans;

// (x1,y1): 현재 있는 곳, (x2,y2): 다음 있는 곳, (cx,cy): 다음 벽 체크할 곳
bool can(int x1, int y1, int x2, int y2, int cx, int cy)
{
	return a[x1][y1] == '.' && a[x2][y2] == '.' && a[x1 + cx][y1 + cy] == 'X' && a[x2 + cx][y2 + cy] == 'X';
}

//
void go(int dirx, int diry, int cx, int cy)
{
	for (int i = 1; i < n - 1; i++) // 맨 위, 맨 아래 행 제외
	{
		for (int j = 1; j < m - 1; j++) // 맨 왼쪽, 맨 아래쪽 열 제회
		{
			if (can(i, j, i + dirx, j + diry, cx, cy)) // 지금 있는 곳이 빈 공간이고, 다음 있는 곳이 벽이면
			{
				i += dirx;
				j += diry;
				ans++;
			}
		}
	}
}

void go2(int dirx, int diry, int cx, int cy)
{
	for (int j = 1; j < m - 1; j++) // 맨 위, 맨 아래 행 제외
	{
		for (int i = 1; i < n - 1; i++) // 맨 왼쪽, 맨 아래쪽 열 제회
		{
			if (can(i, j, i + dirx, j + diry, cx, cy)) // 지금 있는 곳이 빈 공간이고, 다음 있는 곳이 벽이면
			{
				i += dirx;
				j += diry;
				ans++;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	go(0, 1, -1, 0);
	go(0, 1, 1, 0);
	go2(1, 0, 0, -1);
	go2(1, 0, 0, 1);

	cout << ans;
}