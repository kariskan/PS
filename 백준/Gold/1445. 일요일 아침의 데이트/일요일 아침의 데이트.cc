#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char map[50][50];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
pair<int, int> dis[50][50];

struct compare
{
	bool operator()(pair<pair<int, int>, pair<int, int>> &p1, pair<pair<int, int>, pair<int, int>> &p2)
	{
		if (p1.first.first == p2.first.first)
		{
			return p1.first.second > p2.first.second;
		}
		return p1.first.first > p2.first.first;
	}
};

bool isGarbage(pair<int, int> p)
{
	return map[p.first][p.second] == 'g';
}

bool isAdjecant(pair<int, int> p)
{
	if (map[p.first][p.second] != '.')
	{
		return false;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = p.first + dx[i];
		int ny = p.second + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 'g')
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int startx, starty, endx, endy;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
			{
				startx = i;
				starty = j;
			}
			if (map[i][j] == 'F')
			{
				endx = i;
				endy = j;
			}
			dis[i][j].first = dis[i][j].second = 987654321;
		}
	}

	priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, compare> pq;
	pq.push({{0, 0}, {startx, starty}});
	dis[startx][starty] = {0, 0};

	while (!pq.empty())
	{
		int cost1 = pq.top().first.first;
		int cost2 = pq.top().first.second;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			bool gc = isGarbage({nx, ny});
			bool ac = isAdjecant({nx, ny});
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				int newCost = cost1 + (gc ? 1 : 0);
				int newCost2 = cost2 + (ac ? 1 : 0);
				if (newCost < dis[nx][ny].first || ((newCost == dis[nx][ny].first && newCost2 < dis[nx][ny].second)))
				{
					pq.push({{newCost, newCost2}, {nx, ny}});
					dis[nx][ny] = {newCost, newCost2};
				}
			}
		}
	}

	cout << dis[endx][endy].first << ' ' << dis[endx][endy].second;
}