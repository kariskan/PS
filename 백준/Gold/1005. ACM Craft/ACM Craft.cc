#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int t, n, k;
int dp[1000];
int main() {
	cin >> t;
	while (t--) {

		cin >> n >> k;
		vector<vector<int>> v(n + 1);
		vector<vector<int>> v2(n + 1);
		vector<int> time(n + 1);
		vector<int> inp(n + 1);

		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v2[b].push_back(a);
			inp[b]++;
		}
		int w;
		cin >> w;
		vector<int> seq;
		seq.push_back(-1);
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (inp[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int a = q.front();
			q.pop();
			seq.push_back(a);
			for (int i = 0; i < v[a].size(); i++) {
				inp[v[a][i]]--;
				if (inp[v[a][i]] == 0) {
					q.push(v[a][i]);
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			int idx = seq[i];
			for (int j = 0; j < v2[idx].size(); j++) {
				if (dp[idx] < dp[v2[idx][j]]) {
					dp[idx] = dp[v2[idx][j]];
				}
			}
			dp[idx] += time[idx];
		}
		cout << dp[w] << '\n';
		memset(dp, 0, sizeof(dp));
	}
}