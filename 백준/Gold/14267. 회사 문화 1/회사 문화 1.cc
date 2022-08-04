#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dp[100001], parent[100001];
vector<vector<int>> v;

void dfs(int node, int pre, int cost) {
	dp[node] += cost;
	for (auto& i : v[node]) {
		if (i != pre) {
			dfs(i, node, dp[node]);
		}
	}
}

int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a != -1) {
			v[a].push_back(i);
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		dp[a] += b;
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << ' ';
	}
}