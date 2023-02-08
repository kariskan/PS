#include <iostream>
using namespace std;
pair<int, int> p[1000];
int main()
{
	int n, t;
	cin >> n >> t;
	int left = 1, right = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
		right = max(right, p[i].second);
	}

	int ans = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		long long leftSum = 0, rightSum = 0;
		int ok = 1;
		for (int i = 0; i < n; i++)
		{
			if (p[i].first > mid)
			{
				ok = 0;
				break;
			}
			leftSum += p[i].first;
			rightSum += min(mid, p[i].second);
		}
		
		if (ok && t >= leftSum && t <= rightSum)
		{
			right = mid - 1;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ans;
}