#include <iostream>
#include <algorithm>
using namespace std;
int a[300001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
	}
	for (int i = 0; i < m; i++)
	{
		int b, c;
		cin >> b >> c;
		cout << a[c] - a[b - 1] << '\n';
	}
}