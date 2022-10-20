#include <iostream>
using namespace std;
int ar[20001];
int main()
{
	int n, a, d;
	cin >> n >> a >> d;
	int ans = 0, x = a;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		if (ar[i] == x)
		{
			ans++;
			x += d;
		}
	}

	cout << ans;
}