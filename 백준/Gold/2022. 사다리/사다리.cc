#include <iostream>
#include <cmath>
using namespace std;

double x, y, c;

int main()
{
	cin >> x >> y >> c;
	double ans = 0;
	double left = 0, right = min(x, y);
	for (int i = 0; i < 10000; i++)
	{
		double mid = (left + right) / 2;
		double yy = sqrt(y * y - mid * mid);
		double xx = sqrt(x * x - mid * mid);
		if (c / yy + c / xx >= 1)
		{
			ans = mid;
			right = mid - 0.0000000001;
		}
		else
		{
			left = mid + 0.0000000001;
		}
	}
	printf("%0.3lf", ans);
}