#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> v;
long long ans;
int dfs(int u, int prv) {
	int ret = 1;
	for (int a : v[u]) {
		if (prv != a) {
			long long cnt = dfs(a, u);
			long long k = n - cnt;
			ans += cnt * k + cnt * (cnt - 1) / 2;
			ret += cnt;
		}
	}
	return ret;
}
int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 1);
	cout << ans;
}