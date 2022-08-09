#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> v;
int inp[101], dp[101];

int get(int node, int pre) {

	if (dp[node]) return dp[node];
	if (node == n) return 1;

	int ret = 0;
	for (auto& i : v[node]) {
		if (i.first != pre) {
			ret += i.second * get(i.first, node);
		}
	}

	return dp[node] = ret;
}

int main() {

	cin >> n >> m;
	v.resize(n + 1);
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[b].push_back({ a,c });
		inp[a]++;
	}

	for (int i = 1; i <= n; i++) {
		if (inp[i] == 0) {
			cout << i << ' ' << get(i, 0) << '\n';
		}
	}
}