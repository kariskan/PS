#include <iostream>
using namespace std;

int a[50];

int main()
{
	int n;
	cin >> n;
	int lc = 1, rc = 1, m = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i > 0 && a[i] > m)
		{
			lc++;
		}
		m = max(m, a[i]);
	}
	m = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] > m)
		{
			rc++;
		}
		m = max(m, a[i]);
	}

	cout << lc << '\n'
		 << rc;
}