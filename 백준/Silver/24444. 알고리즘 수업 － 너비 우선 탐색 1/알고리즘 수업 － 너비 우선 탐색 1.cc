#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int visit[100001], ans[100001], cnt;
int main() {
	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> v(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	queue<int> q;
	q.push(r);
	visit[r] = 1;
	cnt = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		ans[now] = cnt++;

		for (int i = 0; i < v[now].size(); i++) {
			if (!visit[v[now][i]]) {
				visit[v[now][i]] = 1;
				q.push(v[now][i]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
}