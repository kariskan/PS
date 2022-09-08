#include <iostream>
#include <vector>
using namespace std;

int n, s, d;
int depth[100001];
vector<vector<int>> v;

int dfs(int node, int pre) {

	int ret = 0;

	for (auto& i : v[node]) {
		if (i != pre) {
			ret = max(ret, dfs(i, node));
		}
	}

	return depth[node] = ret + 1;
}

int ans = 0;

void dfs2(int node, int pre) {
	if (node != s) ans++;
	for (auto& i : v[node]) {
		if (i != pre) {
			if (depth[i] <= d) continue;
			dfs2(i, node);
		}
	}
}

int main() {
	cin >> n >> s >> d;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(s, 0);
	dfs2(s, 0);

	cout << ans * 2;
}