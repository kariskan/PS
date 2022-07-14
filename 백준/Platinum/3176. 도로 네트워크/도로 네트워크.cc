#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, maxH;
vector<vector<pair<int, int>>> v;
int minDis[100001][20], maxDis[100001][20], parent[100001][20], visit[100001], depth[100001];
void dfs(int idx, int d) {
	visit[idx] = 1;
	depth[idx] = d;
	for (auto& i : v[idx]) {
		if (!visit[i.first]) {
			parent[i.first][0] = idx;
			minDis[i.first][0] = i.second;
			maxDis[i.first][0] = i.second;
			dfs(i.first, d + 1);
		}
	}
}
pair<int, int> mi(int a, int b) {
	int ret1 = 100000002, ret2 = 0;

	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) { //b를 더 낮게 해줌
			swap(a, b);
		}

		int dif = depth[b] - depth[a];

		for (int i = 0; dif > 0; i++) {
			if (dif % 2 == 1) {
				ret1 = min(ret1, minDis[b][i]);
				ret2 = max(ret2, maxDis[b][i]);
				b = parent[b][i];
			}
			dif = dif >> 1;
		}
	}

	if (a != b) {
		for (int i = maxH; i >= 0; i--) {
			if (parent[b][i] != 0 && parent[a][i] != parent[b][i]) {
				ret1 = min(ret1, min(minDis[a][i], minDis[b][i]));
				ret2 = max(ret2, max(maxDis[a][i], maxDis[b][i]));
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		ret1 = min(ret1, min(minDis[a][0], minDis[b][0]));
		ret2 = max(ret2, max(maxDis[a][0], maxDis[b][0]));
	}


	return { ret1,ret2 };
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 20; j++) {
			minDis[i][j] = 10000000;
		}
	}
	minDis[1][0] = 0;
	maxH = (int)ceil(log2(n));
	dfs(1, 0);
	for (int i = 1; i <= maxH; i++) {
		for (int j = 2; j <= n; j++) {
			if (parent[j][i - 1]) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
				minDis[j][i] = min(minDis[j][i - 1], minDis[parent[j][i - 1]][i - 1]);
				maxDis[j][i] = max(maxDis[j][i - 1], maxDis[parent[j][i - 1]][i - 1]);
			}
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> ans = mi(a, b);
		cout << ans.first << ' ' << ans.second << '\n';
	}
}
