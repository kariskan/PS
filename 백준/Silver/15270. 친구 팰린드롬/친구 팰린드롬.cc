#include <iostream>
using namespace std;

int map[51][51], n, m, vis[51], ans;

void go(int idx, int cnt)
{
	ans = max(ans, cnt);
	if (idx > n)
		return;
	go(idx + 1, cnt);

	for (int i = 1; i <= n; i++)
	{
		if (!vis[idx] && !vis[i] && map[idx][i])
		{
			vis[idx] = 1;
			vis[i] = 1;
			go(idx + 1, cnt + 2);
			vis[idx] = 0;
			vis[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	go(0, 0);

	if (ans < n)
	{
		ans++;
	}
	cout << ans;
}