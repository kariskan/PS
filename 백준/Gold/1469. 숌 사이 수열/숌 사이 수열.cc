#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, a[8];
int cnt[17], v[17];
void go(int idx, int c)
{
	if (v[idx] != -1)
	{
		go(idx + 1, c);
		return;
	}
	if (c == 0)
	{
		for (int i = 0; i < n * 2; i++)
		{
			cout << v[i] << ' ';
		}
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		// i번째 수가 한 번도 쓰이지 않았고
		// 올바른 범위에 들어갈 수 있으며,
		// 들어갈 두 곳이 모두 비어있을 때
		if (cnt[a[i]] == 0 && idx + a[i] + 1 < n * 2 && v[idx] == -1 && v[idx + a[i] + 1] == -1)
		{ 
			cnt[a[i]] = 1;
			v[idx] = v[idx + a[i] + 1] = a[i];
			go(idx + 1, c - 1);
			v[idx] = v[idx + a[i] + 1] = -1;
			cnt[a[i]] = 0;
		}
		else
		{
			continue;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	memset(v, -1, sizeof(v));
	go(0, n);
	cout << -1;
}