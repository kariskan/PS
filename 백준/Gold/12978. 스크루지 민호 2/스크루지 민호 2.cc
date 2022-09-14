#include <iostream>
#include <vector>
using namespace std;

int n, dp[100001][2];
vector<vector<int>> v;

int go(int node, int pre, int c) {

	if (dp[node][c] != 0) return dp[node][c];

	int ret = 0;

	for (auto& i : v[node]) {
		if (i != pre) {
			if (c == 1) {
				ret += min(go(i, node, 1), go(i, node, 0));
			}
			else {
				ret += go(i, node, 1);
			}
		}
	}

	return dp[node][c] = ret + c;
}

int main() {

	cin >> n;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout << min(go(1, 0, 0), go(1, 0, 1));
	return 0;
}