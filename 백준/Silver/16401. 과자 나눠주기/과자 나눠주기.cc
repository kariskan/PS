#include <iostream>
using namespace std;

long long a[1000000];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	long long left = 1, right = 1000000000;
	long long ans = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		long long cnt = 0;

		for (int i = 0; i < m; i++)
		{
			cnt += a[i] / mid;
		}

		if (cnt >= n)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;
}