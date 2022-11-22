#include <iostream>
using namespace std;

int a[30000], v[3001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		v[a[i]]++;
	}
	for (int i = 1; i < n; i++)
	{
		int left = i, right = (i + k - 1) % n;
		v[a[left - 1]]--;
		v[a[right]]++;
		int cnt = 0;
		for (int j = 1; j <= d; j++)
		{
			if (v[j])
			{
				cnt++;
			}
		}
		if (!v[c])
		{
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}