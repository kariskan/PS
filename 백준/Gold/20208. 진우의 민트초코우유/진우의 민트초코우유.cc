#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, h, startx, starty, cnt[11], ans;
vector<pair<int, int>> mint;

int getDis(int nowx, int nowy, int nextx, int nexty)
{
	return abs(nowx - nextx) + abs(nowy - nexty);
}

// idx: 현재 먹을 우유의 인덱스, x, y: 현재 위치, nowM: 현재 체력, c: 이때까지 먹은 우유 개수
void go(int x, int y, int nowM, int c)
{
	if (getDis(x, y, startx, starty) <= nowM)
	{
		ans = max(ans, c);
	}
	for (int i = 0; i < mint.size(); i++)
	{
		int dis = getDis(x, y, mint[i].first, mint[i].second);
		if (!cnt[i] && dis <= nowM)
		{
			cnt[i] = 1;
			go(mint[i].first, mint[i].second, nowM - dis + h, c + 1);
			cnt[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				startx = i;
				starty = j;
			}
			else if (a == 2)
			{
				mint.push_back({i, j});
			}
		}
	}

	go(startx, starty, m, 0);

	cout << ans;
}