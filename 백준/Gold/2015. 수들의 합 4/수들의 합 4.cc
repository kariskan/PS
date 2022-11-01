#include <iostream>
#include <map>
using namespace std;

int n, k, a[200001], sum[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	map<int, int> m;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		if (sum[i] == k)
		{
			ans++;
		}
		ans += m[sum[i] - k];
		m[sum[i]]++;
	}

	cout << ans;
}