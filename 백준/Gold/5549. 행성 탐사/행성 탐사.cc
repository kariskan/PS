#include <iostream>
using namespace std;

int n, m, q;
int J[1001][1001], O[1001][1001], I[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c;
			cin >> c;
			if (c == 'J')
			{
				J[i][j]++;
			}
			else if (c == 'O')
			{
				O[i][j]++;
			}
			else
			{
				I[i][j]++;
			}
			J[i][j] += J[i - 1][j] + J[i][j - 1] - J[i - 1][j - 1];
			O[i][j] += O[i - 1][j] + O[i][j - 1] - O[i - 1][j - 1];
			I[i][j] += I[i - 1][j] + I[i][j - 1] - I[i - 1][j - 1];
		}
	}

	for (int i = 0; i < q; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << J[c][d] - J[a - 1][d] - J[c][b - 1] + J[a - 1][b - 1]
			 << ' ' << O[c][d] - O[a - 1][d] - O[c][b - 1] + O[a - 1][b - 1]
			 << ' ' << I[c][d] - I[a - 1][d] - I[c][b - 1] + I[a - 1][b - 1]
			 << '\n';
	}
}