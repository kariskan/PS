#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string map[50];

	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	int k;
	cin >> k;

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int zCnt = 0;
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '0')
			{
				zCnt++;
			}
		}
		if (zCnt <= k && zCnt % 2 == k % 2)
		{
			int cnt = 0;
			for (int t = 0; t < n; t++)
			{
				if (map[i] == map[t])
				{
					cnt++;
				}
			}
			ans = max(ans, cnt);
		}
	}

	cout << ans;
}