#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a[9], vis[9];
vector<int> v;
bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
void go(int sum, int idx, int cnt)
{
	if (cnt == m)
	{
		if (isPrime(sum))
		{
			v.push_back(sum);
		}
		return;
	}
	if (idx >= n)
	{
		return;
	}
	go(sum, idx + 1, cnt);
	vis[idx] = 1;
	go(sum + a[idx], idx + 1, cnt + 1);
	vis[idx] = 0;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	go(0, 0, 0);
	if (v.empty())
	{
		cout << -1;
		return 0;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto &i : v)
	{
		cout << i << ' ';
	}
}