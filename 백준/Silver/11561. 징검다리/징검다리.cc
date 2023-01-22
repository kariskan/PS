#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		long long left = 1, right = 2 * 1e8;
		long long ans = 0;
		while (left <= right)
		{
			long long mid = (left + right) / 2;
			if ((mid * (mid + 1)) / 2 > n)
			{
				right = mid - 1;
			}
			else
			{
				ans = max(ans, mid);
				left = mid + 1;
			}
		}
		cout << ans << '\n';
	}
}