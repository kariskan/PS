#include <iostream>
using namespace std;

int n, b, w;
char a[300000];

int main()
{
	cin >> n >> b >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int left = 0, right = -1;
	int bCnt = 0, wCnt = 0;

	int ans = 0;

	while (right < n)
	{
		right++;
		if (right == n)
		{
			break;
		}
		if (a[right] == 'W')
		{
			wCnt++;
		}
		else
		{
			bCnt++;
		}

		while (bCnt > b && left <= right)
		{
			if (a[left] == 'W')
			{
				wCnt--;
			}
			else
			{
				bCnt--;
			}
			left++;
		}
		if (bCnt <= b && wCnt >= w)
		{
			ans = max(ans, right - left + 1);
		}
	}

	cout << ans;
}