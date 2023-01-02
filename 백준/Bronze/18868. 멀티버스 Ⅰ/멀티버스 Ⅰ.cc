#include <iostream>
using namespace std;

int a[10][200];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int ok = 1;
			for (int k = 0; k < m; k++)
			{
				for (int l = k + 1; l < m; l++)
				{
					if (!(a[i][k] > a[i][l] && a[j][k] > a[j][l]) &&
						!(a[i][k] < a[i][l] && a[j][k] < a[j][l]) &&
						!(a[i][k] == a[i][l] && a[j][k] == a[j][l]))
					{
						ok = 0;
						break;
					}
				}
				if (!ok)
					break;
			}
			if (ok)
			{
				ans++;
			}
		}
	}
	cout << ans;
}