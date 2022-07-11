#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int inp[501];
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	vector<vector<int>> v2(n + 1);
	int time[501] = { 0, };
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		time[i] = t;
		while (1) {
			int a;
			cin >> a;
			if (a == -1)break;
			inp[i]++;
			v[a].push_back(i);
			v2[i].push_back(a);
		}
	}
	vector<int> seq;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inp[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		seq.push_back(node);
		for (int i = 0; i < v[node].size(); i++) {
			inp[v[node][i]]--;
			if (inp[v[node][i]] == 0) {
				q.push(v[node][i]);
			}
		}
	}
	vector<int> ans(n + 1);
	for (int i = 0; i < seq.size(); i++) {
		int node = seq[i];
		int t = 0;
		for (int j = 0; j < v2[node].size(); j++) {
			if (t == 0 || t < ans[v2[node][j]]) {
				t = ans[v2[node][j]];
			}
		}
		ans[node] = t + time[node];
	}
	for (int i = 1; i <= n; i++)cout << ans[i] << '\n';
}