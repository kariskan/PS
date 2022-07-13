#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
int parent[100001][20];
int depth[100001], visit[100001];
int height, maxH;
vector<vector<int>> v;
void dfs(int idx, int dep) {
	visit[idx] = 1;
	depth[idx] = dep;
	for (auto i : v[idx]) {
		if (!visit[i]) {
			visit[i] = 1;
			parent[i][0] = idx;
			dfs(i, dep + 1);
		}
	}
}

int go(int a, int b) {
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}

		for (int i = maxH; i >= 0; i--) {
			if (depth[a] <= depth[parent[b][i]]) {
				b = parent[b][i];
			}
		}
	}
	
	int ret = a;
	if (a != b) {
		for (int i = maxH; i >= 0; i--) {
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 1);
	maxH = (int)floor(log2(n));
	for (int i = 1; i <= maxH; i++) {
		for (int j = 2; j <= n; j++) {
			if (parent[j][i - 1]) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
			}
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << go(a, b) << '\n';
	}
	return 0;
}