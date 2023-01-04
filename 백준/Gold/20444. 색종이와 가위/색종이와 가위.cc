#include <iostream>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;

	long long start = 0, end = n;
	long long mid = (start + end) / 2;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if ((mid + 1) * (n - mid + 1) == k)
		{
			cout << "YES";
			return 0;
		}
		else if ((mid + 1) * (n - mid + 1) > k)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << "NO";
}