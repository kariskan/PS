#include <iostream>
using namespace std;

long long a[300001];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] < a[i + 1])
		{
			// x * a[i] >= a[i + 1]
			long long x = (a[i + 1] - a[i]) / a[i];
			if (a[i + 1] % a[i] != 0)
			{
				x++;
			}
			a[i] += a[i] * x;
		}
	}

	cout << a[0];
}