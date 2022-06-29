#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int n, m, r;
int visit[100001];
int cnt = 1;
int ans[100001];
void dfs(int idx) {
	ans[idx] = cnt++;
	sort(v[idx].begin(), v[idx].end());
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visit[v[idx][i]]) {
			visit[v[idx][i]] = 1;
			dfs(v[idx][i]);
		}
	}
}

int main() {
	cin >> n >> m >> r;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visit[r] = 1;
	dfs(r);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}
}