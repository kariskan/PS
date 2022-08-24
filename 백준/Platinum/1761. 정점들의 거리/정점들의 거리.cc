#include <iostream>
#include <vector>
using namespace std;

int depth[40001], dp[40001][20], len[40001][20], n;
vector<vector<pair<int, int>>> v;

int lca(int a, int b) {

	int ret = 0;

	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}

		for (int i = 19; i >= 0; i--) {
			if (depth[a] <= depth[dp[b][i]]) {
				ret += len[b][i];
				b = dp[b][i];
			}
		}
	}

	if (a != b) {
		int pre = 0;
		for (int i = 19; i >= 0; i--) {
			if (!dp[a][i]) continue;
			if (dp[a][i] && dp[a][i] != dp[b][i]) {
				ret += len[a][i] + len[b][i];
				a = dp[a][i];
				b = dp[b][i];
			}
			ret += len[a][i] + len[b][i] - pre;
			pre = len[a][i] + len[b][i];
		}
	}
	return ret;
}

void go(int node, int pre, int h) {
	depth[node] = h;
	dp[node][0] = pre;

	for (auto& i : v[node]) {
		if (i.first != pre) {
			go(i.first, node, h + 1);
			len[i.first][0] = i.second;
		}
	}
}

int main() {

	cin >> n;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {

		int a, b, c; cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	go(1, 0, 1);

	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
			len[i][j] = len[dp[i][j - 1]][j - 1] + len[i][j - 1];
		}
	}

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}