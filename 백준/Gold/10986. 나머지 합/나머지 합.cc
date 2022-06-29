#include <iostream>
#include <vector>
using namespace std;

int n, m;
long long sum[1000001], cnt[1000001] = { 1, };
int main() {
	cin >> n >> m;
	vector<vector<long long>> v(m);
	v[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		sum[i] = sum[i - 1] + a;
		v[sum[i] % m].push_back(sum[i]);
		cnt[i] = 1;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (sum[i] < m && sum[i] != 0)continue;
		if (v[sum[i] % m].empty())continue;
		ans += v[sum[i] % m].size() - (cnt[sum[i] % m]++);
	}
	cout << ans;
}