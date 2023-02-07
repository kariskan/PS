#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char map[22][22];
vector<string> v;

string go(int dir, int i, int j)
{
	string res = "";
	if (dir == 0)
	{ // 아래
		while (map[i][j] != '#' && map[i][j] != '\0')
		{
			res += map[i][j];
			i++;
		}
		return res;
	}
	else
	{
		while (map[i][j] != '#' && map[i][j] != '\0')
		{
			res += map[i][j];
			j++;
		}
		return res;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			// 위, 왼쪽 모두 비어있다.
			if ((map[i - 1][j] == '#' || map[i - 1][j] == '\0') && (map[i][j - 1] == '#' || map[i][j - 1] == '\0'))
			{
				v.push_back(go(0, i, j));
				v.push_back(go(1, i, j));
			}
			// 위만 비어있다.
			else if ((map[i - 1][j] == '#' || map[i - 1][j] == '\0'))
			{
				v.push_back(go(0, i, j));
			}
			// 왼쪽만 비어있다.
			else if (map[i][j - 1] == '#' || map[i][j - 1] == '\0')
			{
				v.push_back(go(1, i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].size() >= 2)
		{
			cout << v[i];
			return 0;
		}
	}
}