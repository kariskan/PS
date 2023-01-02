#include <iostream>
using namespace std;

char map[50][5][7];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				cin >> map[i][j][k];
			}
		}
	}
	int ans = 987654321, ansi, ansj;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 5; k++)
			{
				for (int l = 0; l < 7; l++)
				{
					if (map[i][k][l] != map[j][k][l])
					{
						cnt++;
					}
				}
			}
			if (ans > cnt)
			{
				ans = cnt;
				ansi = i + 1;
				ansj = j + 1;
			}
		}
	}
	cout << ansi << ' ' << ansj;
}