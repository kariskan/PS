#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> v;
queue<int> q;
int inpCnt[1001];
int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		int pre = -1;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			if (j != 0) {
				v[pre].push_back(b);
				inpCnt[b]++;
			}
			pre = b;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (inpCnt[i] == 0) {
			q.push(i);
		}
	}
	vector<int> ans;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for (int i = 0; i < v[node].size(); i++) {
			inpCnt[v[node][i]]--;
			if (inpCnt[v[node][i]] == 0) { //입력 간선이 0개일 때
				q.push(v[node][i]);
			}
		}
	}
	if (ans.size() != n) {
		cout << 0;
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
}