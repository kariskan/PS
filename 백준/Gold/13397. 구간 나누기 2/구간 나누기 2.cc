#include <iostream>
using namespace std;
int a[5000];
int main()
{
	int n, m;
	cin >> n >> m;
	int start = 0, end = 0, mid;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		end = max(end, a[i]);
	}
	int ans = 987654321;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int groupCnt = 0, minNum = a[0], maxNum = a[0];

		for (int i = 0; i < n; i++)
		{
			minNum = min(minNum, a[i]);
			maxNum = max(maxNum, a[i]);
			if (maxNum - minNum > mid)
			{
				groupCnt++;
				maxNum = a[i];
				minNum = a[i];
			}
		}

		groupCnt++;

		if (groupCnt > m)
		{
			start = mid + 1;
		}
		else
		{
			ans = min(ans, mid);
			end = mid - 1;
		}
	}

	cout << ans;
}