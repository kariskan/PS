#include <iostream>
#include <cstring>
using namespace std;

int n, map[11][11], ans, now[11];

void go(int idx, int sum)
{
	if (idx == 11)
	{
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 11; i++)
	{
		if (!now[i] && map[idx][i])
		{
			now[i] = 1;
			go(idx + 1, sum + map[idx][i]);
			now[i] = 0;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				cin >> map[i][j];
			}
		}
		go(0, 0);
		cout << ans << '\n';
		ans = 0;
		memset(map, 0, sizeof(map));
		memset(now, 0, sizeof(now));
	}
}