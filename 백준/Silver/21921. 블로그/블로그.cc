#include <iostream>
using namespace std;

int a[250000], n, x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int cnt = 1, sum = 0, s = 0;
	for (int i = 0; i < x; i++)
	{
		sum += a[i];
	}
	s = sum;
	for (int i = 1; i <= n - x; i++)
	{
		int t = s - a[i - 1] + a[i + x - 1];
		if (t > sum)
		{
			sum = t;
			cnt = 1;
		}
		else if (t == sum)
		{
			cnt++;
		}
		s = t;
	}
	if (sum == 0)
	{
		cout << "SAD\n";
	}
	else
	{
		cout << sum << '\n'
			 << cnt;
	}
}