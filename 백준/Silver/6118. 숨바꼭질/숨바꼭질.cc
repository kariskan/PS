#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> v;
int visit[20001];

int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	int maxLen = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();

		maxLen = max(maxLen, visit[a]);

		for (auto& i : v[a]) {
			if (!visit[i]) {
				visit[i] = visit[a] + 1;
				q.push(i);
			}
		}
	}
	int ans = -1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == maxLen) {
			if (ans == -1)	ans = i;
			cnt++;
		}
	}
	cout << ans << ' ' << maxLen - 1 << ' ' << cnt;
}