#include <iostream>
using namespace std;
int a[1000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		int removeNum;
		if (i == n)
		{
			removeNum = -1;
		}
		else
		{
			removeNum = a[i];
		}
		int len = 0, lastNum = -1;
		for (int j = 0; j < n; j++)
		{
			if (a[j] == removeNum)
			{
				continue;
			}
			if (a[j] == lastNum)
			{
				len++;
			}
			else
			{
				ans = max(ans, len);
				len = 1;
			}
			lastNum = a[j];
		}
		ans = max(ans, len);
	}
	cout << ans;
}