#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int map[1001][1001] = {
			0,
		},
			sum[1001][1001] = {
				0,
			};
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, c, d, e;
			cin >> a >> b >> c >> d >> e;
			a--;
			b--;
			c--;
			d--;
			sum[a][b] += e;
			sum[c + 1][d + 1] += e;
			sum[a][d + 1] += -e;
			sum[c + 1][b] += -e;
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sum[i][j] += sum[i - 1][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				sum[i][j] += sum[i][j - 1];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] += sum[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			int s = 0;
			for (int j = 0; j < n; j++)
			{
				s += map[i][j];
			}
			cout << s << ' ';
		}
		cout << '\n';
		for (int i = 0; i < n; i++)
		{
			int s = 0;
			for (int j = 0; j < n; j++)
			{
				s += map[j][i];
			}
			cout << s << ' ';
		}
		cout << '\n';
	}
}