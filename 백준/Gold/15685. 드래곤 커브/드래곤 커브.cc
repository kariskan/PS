#include <iostream>
#include <vector>
using namespace std;

int n, map[1000][1000];

pair<int, int> curve(int x, int y, int stX, int stY)
{
	return {stX - stY + y, stY + stX - x};
}

pair<int, int> first(int x, int y, int dir)
{
	if (dir == 0)
	{
		return {x, y + 1};
	}
	if (dir == 1)
	{
		return {x - 1, y};
	}
	if (dir == 2)
	{
		return {x, y - 1};
	}
	return {x + 1, y};
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		swap(a, b);

		vector<pair<int, int>> q;

		q.push_back({a, b});
		q.push_back({first(a, b, c)});
		map[a][b] = map[first(a, b, c).first][first(a, b, c).second] = 1;
		int stX = q.back().first, stY = q.back().second;

		while (d--)
		{
			int siz = q.size() - 1;
			for (int j = siz - 1; j >= 0; j--)
			{
				int x = q[j].first;
				int y = q[j].second;
				pair<int, int> changeCoor = curve(x, y, stX, stY);
				map[changeCoor.first][changeCoor.second] = 1;
				q.push_back(changeCoor);
				if (j == 0)
				{
					stX = changeCoor.first, stY = changeCoor.second;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
			{
				ans++;
			}
		}
	}

	cout << ans;
}