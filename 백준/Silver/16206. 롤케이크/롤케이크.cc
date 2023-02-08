#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	if (a % 10 == 0 && b % 10 != 0)
	{
		return true;
	}
	if (b % 10 == 0 && a % 10 != 0)
	{
		return false;
	}
	return a < b;
}
int a[1000];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n, compare);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		
		while (a[i] > 10 && m)
		{
			a[i] -= 10;
			ans++;
			m--;
		}
		if (a[i] == 10)
		{
			ans++;
		}
	}

	cout << ans;
}