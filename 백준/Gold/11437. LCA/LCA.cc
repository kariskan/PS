#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

vector<vector<int>> v;
int depth[50001], height, parent[50001][20];

void dfs(int node, int h, int pre) {
	depth[node] = h;
	for (auto& i : v[node]) {
		if (i != pre) {
			parent[i][0] = node;
			dfs(i, h + 1, node);
		}
	}
}

int getA(int a, int b) {
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}

		for (int i = height; i >= 0; i--) {
			if (depth[a] <= depth[parent[b][i]]) {
				b = parent[b][i];
			}
		}
	}

	int ret = a;
	if (a != b) {
		for (int i = height; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
			ret = parent[a][i];
		}
	}
	return ret;
}

int main() {
	int n; cin >> n;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1, 1, 0);
	height = (int)floor(log2(n));

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << getA(a, b) << '\n';
	}
	return 0;
}