#include <iostream>
#include <deque>
using namespace std;

deque<int> a, v;
int n, m, cnt;

void velt_rotate()
{
	a.push_front(a.back());
	a.pop_back();

	v.push_front(v.back());
	v.pop_back();

	v[n - 1] = 0;
}

void robot_rotate()
{
	for (int i = n - 2; i >= 0; i--)
	{
		if (v[i] && !v[i + 1] && a[i + 1] > 0)
		{
			v[i] = 0;
			v[i + 1] = 1;
			a[i + 1]--;
			if (a[i + 1] == 0)
			{
				cnt++;
			}
		}
	}
	v[n - 1] = 0;
}

void robot_put()
{
	if (!v[0] && a[0] > 0)
	{
		a[0]--;
		if (a[0] == 0)
		{
			cnt++;
		}
		v[0] = 1;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n * 2; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
		v.push_back(0);
	}
	int ans = 0;
	while (cnt < m)
	{
		ans++;
		velt_rotate();
		robot_rotate();
		robot_put();
	}
	cout << ans;
}