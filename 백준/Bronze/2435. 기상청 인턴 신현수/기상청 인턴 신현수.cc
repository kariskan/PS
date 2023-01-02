#include <iostream>
using namespace std;

int n, m, a[101];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	int ans = -1000000000;
	for (int i = m; i <= n; i++)
	{
		ans = max(ans, a[i] - a[i - m]);
	}
	cout << ans;
}