#include <iostream>
using namespace std;
int a[30][3], r, g, b, n;
int ans = 987654321;
void go(int rr, int gg, int bb, int cnt, int idx)
{
	if (cnt > 7)
	{
		return;
	}

	if (cnt >= 2)
	{
		ans = min(ans, abs(rr / cnt - r) + abs(gg / cnt - g) + abs(bb / cnt - b));
	}
	
	if (idx >= n)
	{
		return;
	}

	go(rr + a[idx][0], gg + a[idx][1], bb + a[idx][2], cnt + 1, idx + 1);
	go(rr, gg, bb, cnt, idx + 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	cin >> r >> g >> b;
	go(0, 0, 0, 0, 0);
	cout << ans;
}