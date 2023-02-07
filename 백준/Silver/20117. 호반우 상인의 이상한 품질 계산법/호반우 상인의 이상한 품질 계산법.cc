#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	int ans = 0;

	for (int i = n - 1; i >= (n + 1) / 2; i--)
	{
		ans += a[i] * 2;
	}
	if (n % 2 == 1)
	{
		ans += a[n / 2];
	}
	cout << ans;
}