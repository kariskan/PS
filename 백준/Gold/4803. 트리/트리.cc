#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> v;
int visit[501];
int ans;
int ok = 1;
void dfs(int now, int pre) {
	visit[now] = 1;
	for (auto& i : v[now]) {
		if (!visit[i]) {
			dfs(i, now);
		}
		else if (i != pre) {
			//isCycle
			ok = 0;
		}
	}
}
int main() {
	int cnt = 1;
	while (1) {
		int n, m;
		cin >> n >> m;
		if (!n && !m)break;
		v.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				ok = 1;
				dfs(i, i);
				if (ok) {
					ans++;
				}
			}
		}
		cout << "Case " << cnt << ": ";
		if (ans == 0)cout << "No trees.";
		else if (ans == 1)cout << "There is one tree.";
		else cout << "A forest of " << ans << " trees.";
		cout << "\n";
		cnt++;
		v.clear();
		ans = 0;
		memset(visit, 0, sizeof(visit));
	}
}