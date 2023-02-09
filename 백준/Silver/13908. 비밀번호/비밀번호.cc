#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m, a[10], ans;

bool check(int c[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (a[i] && !c[i])
		{
			return false;
		}
	}
	return true;
}

void go(int len, int c[10])
{
	if (len > n)
	{
		return;
	}
	if (check(c) && len == n)
	{
		ans++;
	}

	for (int i = 0; i < 10; i++)
	{
		c[i]++;
		go(len + 1, c);
		c[i]--;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		a[k] = 1;
	}
	int c[10] = {
		0,
	};
	go(0, c);
	cout << ans;
}