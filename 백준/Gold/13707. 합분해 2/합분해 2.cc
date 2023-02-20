#include <iostream>
using namespace std;

long long comb[5001][5001];
long long mod = 1000000000;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1)
			{
				comb[i][j] = j;
			}
			else if (j == 1)
			{
				comb[i][j] = 1;
			}
			else
			{
				comb[i][j] = (comb[i - 1][j] % mod + comb[i][j - 1] % mod) % mod;
			}
		}
	}

	cout << comb[n][m];
}