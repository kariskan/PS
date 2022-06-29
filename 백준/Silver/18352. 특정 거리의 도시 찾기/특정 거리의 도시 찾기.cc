#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int visit[300001];
int n, m, k, x;
int main() {
	cin >> n >> m >> k >> x;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	queue<int> q;
	q.push(x);
	visit[x] = 1;
	vector<int> ans;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		if (visit[a] - 1 == k) {
			ans.push_back(a);
			continue;
		}
		for (int i = 0; i < v[a].size(); i++) {
			if (!visit[v[a][i]]) {
				visit[v[a][i]] = visit[a] + 1;
				q.push(v[a][i]);
			}
		}
	}
	if (ans.empty()) {
		cout << -1;
	}
	else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}
	}
	
}