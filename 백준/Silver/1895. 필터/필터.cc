#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[40][40];
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
	int t;
	cin >> t;
	int ans = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			vector<int> v;
			for (int k = i; k < i + 3; k++)
			{
				for (int l = j; l < j + 3; l++)
				{
					v.push_back(a[k][l]);
				}
			}
			sort(v.begin(), v.end());
			int midNum = v[4];
			if (t <= midNum)
			{
				ans++;
			}
		}
	}
	cout << ans;
}