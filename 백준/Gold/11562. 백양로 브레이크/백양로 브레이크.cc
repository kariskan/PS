#include <iostream>
using namespace std;

int n, m, k, map[251][251];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			map[i][j] = 987654321;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = 0;
		if (c == 1)
			map[b][a] = 0;
		else
			map[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] == 0)
					continue;
				else if (map[i][k] != 987654321 && map[k][j] != 987654321)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << map[a][b] << '\n';
	}
}