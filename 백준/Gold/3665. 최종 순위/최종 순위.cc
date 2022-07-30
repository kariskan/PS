#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int map[501][501];
int inp[501], visit[501];
int main() {
	int t; cin >> t;
	while (t--) {
		vector<int> seq;
		int n; cin >> n;
		seq.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> seq[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				map[seq[i]][seq[j]] = 1;
				inp[seq[j]]++;
			}
		}
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			if (map[a][b]) {
				map[a][b] = 0;
				map[b][a] = 1;
				inp[b]--;
				inp[a]++;
			}
			else if (map[b][a]) {
				map[b][a] = 0;
				map[a][b] = 1;
				inp[a]--;
				inp[b]++;
			}
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (inp[i] == 0) {
				q.push(i);
			}
		}
		vector<int> ans;
		while (!q.empty()) {
			if (q.size() > 1) {
				cout << "?\n";
				break;
			}
			int a = q.front();
			q.pop();
			visit[a] = 1;
			ans.push_back(a);

			for (int i = 1; i <= n; i++) {
				if (visit[i])continue;
				if (map[a][i]) {
					inp[i]--;
				}
				if (inp[i] == 0) {
					q.push(i);
				}
			}
		}
		int ok = 1;
		for (int i = 1; i <= n; i++) {
			if (inp[i]) {
				ok = 0; break;
			}
		}

		if (!ok) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			for (auto i : ans) {
				cout << i << " ";
			}
			cout << "\n";
		}
		memset(map, 0, sizeof(map));
		memset(inp, 0, sizeof(inp));
		memset(visit, 0, sizeof(visit));
	}
}