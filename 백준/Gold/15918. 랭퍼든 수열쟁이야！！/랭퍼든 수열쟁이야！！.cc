#include <iostream>
using namespace std;

int ans, n, x, y, a[12], r[24], c[30];

void go(int idx)
{
	if (r[idx])
	{
		go(idx + 1);
		return;
	}
	if (idx == 2 * n)
	{
		ans++;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!c[i] && !r[idx] && !r[idx + i + 1] && idx + i + 1 < 2 * n)
		{
			c[i] = 1;
			r[idx] = r[idx + i + 1] = 1;
			go(idx + 1);
			c[i] = 0;
			r[idx] = r[idx + i + 1] = 0;
		}
	}
}

int main()
{
	cin >> n >> x >> y;
	r[x - 1] = r[y - 1] = y - x - 1;
	c[y - x - 1] = 1;
	go(0);
	cout << ans;
}