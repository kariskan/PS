#include <iostream>
using namespace std;
int n, sum, cnt, vis[4000000], a[13];

void go(int now, int idx)
{
	if (now > 0) {
        if(!vis[now]) {
		    vis[now] = 1;
		    cnt++;
        }
	}
	if (idx == n) {
		return;
	}

	go(now, idx + 1);
	go(now + a[idx], idx + 1);
	go(now - a[idx], idx + 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	go(0, 0);

	cout << sum - cnt;
}