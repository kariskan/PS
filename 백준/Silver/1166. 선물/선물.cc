#include <iostream>
using namespace std;

int main()
{
	long long n, l, w, h;
	cin >> n >> l >> w >> h;

	double left = 0.000000001, right = 1000000000;
	double ans = 0;
	for (int i = 0; i < 10000; i++)
	{
		double mid = (left + right) / 2;

		long long cnt = (long long)(l / mid) * (long long)(w / mid) * (long long)(h / mid);
		if (cnt >= n)
		{
			left = mid;
			ans = mid;
		}
		else
		{
			right = mid;
		}
	}

	printf("%.10f", ans);
}