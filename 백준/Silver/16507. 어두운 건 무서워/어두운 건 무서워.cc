#include <iostream>
using namespace std;

int r, c, q;
int a[1001][1001], s[1001][1001];

int main()
{
	cin >> r >> c >> q;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	for (int i = 0; i < q; i++)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		cout << (s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) << '\n';
	}
}