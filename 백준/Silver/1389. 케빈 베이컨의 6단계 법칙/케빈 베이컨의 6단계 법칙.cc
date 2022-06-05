#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


vector<vector<int>> v;
int n, m, s;
void run(int idx) {
	queue<int> q;
	q.push(idx);
	int visit[101] = { 0, };
	visit[idx] = 1;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		s += visit[a];
		for (int i = 0; i < v[a].size(); i++) {
			if (!visit[v[a][i]]) {
				visit[v[a][i]] = visit[a] + 1;
				q.push(v[a][i]);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans = 1000000000, ansi = -1;
	for (int i = 1; i <= n; i++) {
		s = 0;
		run(i);
		if (ans > s) {
			ans = s;
			ansi = i;
		}
	}
	cout << ansi;
}