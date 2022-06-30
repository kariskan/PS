#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int visit[100001], ans[100001], cnt = 1;
int n, m, r;
bool compare(int& a, int& b) {
	return a > b;
}
void dfs(int idx) {
	visit[idx] = 1;
	ans[idx] = cnt++;

	for (int i = 0; i < v[idx].size(); i++) {
		if (!visit[v[idx][i]]) {
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
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end(), compare);
	}
	dfs(r);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
}