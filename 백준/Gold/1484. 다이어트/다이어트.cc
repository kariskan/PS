#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	int left = 1, right = 2;
	int ok = 0;
	while (left < right)
	{
		if (right * right - left * left > n)
		{
			left++;
		}
		else
		{
			if (right * right - left * left == n)
			{
				ok = 1;
				cout << right << '\n';
			}
			right++;
		}
	}

	if (!ok)
	{
		cout << -1;
	}
}