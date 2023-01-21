#include <iostream>
using namespace std;

int a[100001], s[100001];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		int b, c, d;
		cin >> b >> c >> d;
		s[b] += d;
		s[c + 1] -= d;
	}
	for (int i = 1; i <= n; i++)
	{
		s[i] += s[i - 1];
		cout << s[i] + a[i] << ' ';
	}
}