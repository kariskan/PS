#include <iostream>
using namespace std;

int main()
{
	int m;
	cin >> m;
	int left = 1, right = 500000000;
	int ans = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		int cnt = 0;
		int five = 5;
		while (five <= mid)
		{
			cnt += mid / five;
			five *= 5;
		}

		if (cnt >= m)
		{
			right = mid - 1;
			if(cnt==m)
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ans;
}