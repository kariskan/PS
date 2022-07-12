#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<int>> edge;
vector<vector<int>> ans;
stack<int> st;
int v, e, id = 1;
int visit[10001], finish[10001];

int dfs(int idx) {
	visit[idx] = id++;
	st.push(idx);

	int res = visit[idx];
	for (int i = 0; i < edge[idx].size(); i++) {
		if (!visit[edge[idx][i]]) {
			res = min(res, dfs(edge[idx][i]));
		}
		else if (!finish[edge[idx][i]]) {
			res = min(res, visit[edge[idx][i]]);
		}
	}

	if (res == visit[idx]) {
		vector<int> temp;
		while (st.top() != idx) {
			temp.push_back(st.top());
			finish[st.top()] = 1;
			st.pop();
		}
		temp.push_back(st.top());
		finish[st.top()] = 1;
		st.pop();
		sort(temp.begin(), temp.end());
		ans.push_back(temp);
	}
	return res;
}
int main() {
	cin >> v >> e;
	edge.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= v; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	for (int i = 1; i <= v; i++) {
		if(!visit[i]) dfs(i);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << "-1\n";
	}
}