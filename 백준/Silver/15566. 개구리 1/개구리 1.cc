#include <iostream>
using namespace std;
int n, m;
int inter[16][5], map[16][16];
pair<int, int> favor[16];
int status[16], frog[16];
void go(int idx)
{
	if (idx > n)
	{
		int ok = 1;
		for (int i = 1; i <= n; i++)
		{
			if (frog[i] == 0 || status[i] == 0)
			{
				ok = 0;
				break;
			}
			for (int j = 1; j <= n; j++)
			{
				if (i == j || map[i][j] == 0)
					continue;
				if (inter[status[i]][map[i][j]] != inter[status[j]][map[i][j]])
				{
					ok = 0;
					break;
				}
			}
		}
		if (ok)
		{
			cout << "YES\n";
			for (int i = 1; i <= n; i++)
			{
				cout << status[i] << ' ';
			}
			exit(0);
		}
		return;
	}

	if (!status[favor[idx].first])
	{
		status[favor[idx].first] = idx;
		frog[idx] = favor[idx].first;
		go(idx + 1);
		status[favor[idx].first] = 0;
		frog[idx] = 0;
	}
	if (!status[favor[idx].second])
	{
		status[favor[idx].second] = idx;
		frog[idx] = favor[idx].second;
		go(idx + 1);
		status[favor[idx].second] = 0;
		frog[idx] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> inter[i][1] >> inter[i][2] >> inter[i][3] >> inter[i][4];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> favor[i].first >> favor[i].second;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = map[b][a] = c;
	}
	go(1);
	cout << "NO";
}