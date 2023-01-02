#include <iostream>
using namespace std;

int a[1000];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 987654321;
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		if (a[i] < 1 + i * m)
		{
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (j > i && a[j] - (a[i] + (j - i) * m) != 0)
			{
				k++;
			}
			else if (j < i && a[j] - (a[i] - (i - j) * m) != 0)
			{
				k++;
			}
		}
		ans = min(ans, k);
	}
	cout << ans;
}