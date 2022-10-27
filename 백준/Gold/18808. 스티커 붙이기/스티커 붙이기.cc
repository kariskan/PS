#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, k, map[40][40], ans = 0;

struct sticker
{
	int r;
	int c;
	int board[10][10] = {
		0,
	};
};

vector<sticker> v;

bool range(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool canPlaced(int x, int y, sticker s)
{

	for (int i = 0; i < s.r; i++)
	{
		for (int j = 0; j < s.c; j++)
		{
			if (!range(x + i, y + j))
				return false;
			if (map[x + i][j + y] == 1 && s.board[i][j] == 1)
				return false;
		}
	}

	return true;
}

void rotate(int seq)
{
	int temp[10][10] = {
		0,
	};

	for (int i = 0; i < v[seq].r; i++)
	{
		for (int j = 0; j < v[seq].c; j++)
		{
			temp[j][v[seq].r - i - 1] = v[seq].board[i][j];
		}
	}

	swap(v[seq].r, v[seq].c);

	memset(v[seq].board, 0, sizeof(v[seq].board));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			v[seq].board[i][j] = temp[i][j];
		}
	}
}

void place(int x, int y, sticker s)
{
	for (int i = 0; i < s.r; i++)
	{
		for (int j = 0; j < s.c; j++)
		{
			if(s.board[i][j] == 1)
			map[x + i][y + j] = s.board[i][j];
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		sticker s;
		cin >> s.r >> s.c;
		for (int j1 = 0; j1 < s.r; j1++)
		{
			for (int j2 = 0; j2 < s.c; j2++)
			{
				cin >> s.board[j1][j2];
			}
		}
		v.push_back(s);
	}

	for (int seq = 0; seq < k; seq++)
	{
		int ok = 0;
		for (int rot = 0; rot < 4; rot++)
		{
			if (rot != 0)
			{
				rotate(seq);
			}
			for (int i = 0; i < n; i++)
			{
				// find where
				for (int j = 0; j < m; j++)
				{
					if (i + v[seq].r > n || j + v[seq].c > m) continue;
					if (canPlaced(i, j, v[seq]))
					{
						place(i, j, v[seq]);
						ok = 1;
						break;
					}
				}
				if (ok)
					break;
			}
			if (ok)
				break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j])
			{
				ans++;
			}
		}
	}

	cout << ans;
}