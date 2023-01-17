#include <iostream>
using namespace std;
int vis[8][7], map[8][7], vis2[7][7];
int x[4] = {1, 0, 0, -1};
int y[4] = {0, -1, 1, 0};
int ans;
void go(int i, int j, int cnt)
{
	if (j == 7)
	{
		go(i + 1, 0, cnt);
		return;
	}
	if (i == 8)
	{
		if (cnt == 0)
		{
			ans++;
		}
		return;
	}
	if (vis[i][j])
	{
		go(i, j + 1, cnt);
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		int nx = i + x[k];
		int ny = j + y[k];
		int minV = min(map[i][j], map[nx][ny]);
		int maxV = max(map[i][j], map[nx][ny]);
		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 7 && !vis[i][j] && !vis[nx][ny] && !vis2[minV][maxV])
		{
			vis[i][j] = vis[nx][ny] = vis2[minV][maxV] = 1;
			go(i, j + 1, cnt - 2);
			vis[i][j] = vis[nx][ny] = vis2[minV][maxV] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	go(0, 0, 56);

	cout << ans;
}