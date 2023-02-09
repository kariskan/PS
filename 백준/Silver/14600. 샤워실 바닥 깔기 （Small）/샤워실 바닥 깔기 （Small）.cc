#include <iostream>
#include <cmath>
using namespace std;

int map[4][4];
int k, x, y;
pair<int, int> tile[4][3] = {
	{{0, 0}, {0, 1}, {1, 0}},
	{{0, 0}, {1, 0}, {0, -1}},
	{{0, 0}, {0, -1}, {-1, 0}},
	{{0, 0}, {-1, 0}, {0, 1}}};

bool check(int i, int j)
{
	int t = (int)pow(2, k);
	return i >= 0 && i < t && j >= 0 && j < t;
}
int cnt = 1;
void go(int i, int j, int c)
{
	if (map[i][j]) // 이미 타일이 차있을 경우
	{
		go(i, j + 1, c);
		return;
	}
	if (j >= (int)pow(2, k)) // 가로 범위를 벗어났을 경우
	{
		go(i + 1, 0, c);
		return;
	}
	if (i >= (int)pow(2, k)) // 모든 경우를 체크했을 경우
	{
		if (cnt == (int)pow(2, k) * (int)pow(2, k)) // 모든 타일을 깔았을 경우
		{
			for (int i = 0; i < (int)pow(2, k); i++)
			{
				for (int j = 0; j < (int)pow(2, k); j++)
				{
					cout << map[i][j] << ' ';
				}
				cout << '\n';
			}
			exit(0);
		}
		return;
	}

	for (int t = 0; t < 4; t++) // 모든 타일을 대본다.
	{
		int ok = 1;
		for (int l = 0; l < 3; l++)
		{
			// 타일을 깔 수 없는 범위이거나, 이미 타일이 깔려있을 경우
			if (!(check(i + tile[t][l].first, j + tile[t][l].second) && !map[i + tile[t][l].first][j + tile[t][l].second]))
			{
				ok = 0;
				break;
			}
		}
		if (ok) // 타일을 깔 수 있을 경우
		{
			for (int l = 0; l < 3; l++)
			{
				map[i + tile[t][l].first][j + tile[t][l].second] = c; // 타일을 깔고
			}
			cnt += 3;	  // 타일 개수를 +
			go(i, j + 1, c + 1); // 다음 경우
			for (int l = 0; l < 3; l++)
			{
				map[i + tile[t][l].first][j + tile[t][l].second] = 0; // 타일을 다시 뺀다
			}
			cnt -= 3;
		}
	}

	go(i, j + 1, c);
}

int main()
{
	cin >> k >> y >> x;
	y--;
	x = (int)pow(2, k) - x;
	map[x][y] = -1;
	go(0, 0, 1);

	cout << -1;
}