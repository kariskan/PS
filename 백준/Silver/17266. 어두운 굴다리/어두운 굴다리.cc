#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	sort(a, a + m);
	int start = 1, end = 100000;
	int ans = 987654321;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int recent = 0, ok = 1;
		for (int i = 0; i < m; i++)
		{
			if (a[i] - mid > recent)
			{
				ok = 0;
				break;
			}
			recent = a[i] + mid;
		}
		
		if (recent < n) {
			ok = 0;
		}

		if (ok)
		{
			ans = min(ans, mid);
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	
	cout << ans;
}