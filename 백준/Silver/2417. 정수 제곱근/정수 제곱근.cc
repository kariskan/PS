#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
long long n;

int main()
{
	cin >> n;
	long long left = 0, right = sqrt(n);
	long long mid = (left + right) / 2;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (sqrt(n) > mid)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	if (mid * mid >= n)
		cout << mid;
	else cout << mid + 1;
}