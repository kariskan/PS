#include <iostream>
using namespace std;

int a[50000], sum;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	int left = 0, right = 1;
	int now = a[0];
	int ans = 0;

	while (left < right && right < n)
	{
		ans = max(ans, min(now, sum - now));

		if (now < sum / 2)
		{
			now += a[right];
			right++;
		}
		else
		{
			now -= a[left];
			left++;
		}
	}

	cout << ans;
}