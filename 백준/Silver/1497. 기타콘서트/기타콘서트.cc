#include <iostream>
#include <algorithm>
using namespace std;
int a[10][50];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		for (int j = 0; j < s2.length(); j++)
		{
			if (s2[j] == 'Y')
			{
				a[i][j] = 1;
			}
		}
	}
	int ans = -1;
	int maxSong = 0;
	for (int i = 1; i <= n; i++)
	{
		int t[10] = {
			0,
		};
		for (int j = n - 1; j > n - i - 1; j--)
		{
			t[j] = 1;
		}
		do
		{
			int song[50] = {
				0,
			};
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (t[j])
				{
					for (int k = 0; k < m; k++)
					{
						if (a[j][k] && !song[k])
						{
							song[k] = 1;
							cnt++;
						}
					}
				}
			}
			if (cnt > maxSong)
			{
				ans = i;
				maxSong = cnt;
			}
		} while (next_permutation(t, t + n));
	}
	cout << ans;
}