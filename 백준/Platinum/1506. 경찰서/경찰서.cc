#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v, info;
vector<int> cost, st, temp;
int visit[101], scc[101], id = 1;
int n;
int dfs(int idx) {
	int ret = visit[idx] = id++;
	st.push_back(idx);
	for (auto i : v[idx]) {
		if (!visit[i]) {
			ret = min(ret, dfs(i));
		}
		else if (!scc[i]) {
			ret = min(ret, visit[i]);
		}
	}

	if (ret == visit[idx]) {
		while (1) {
			int t = st.back();
			st.pop_back();
			scc[t] = 1;
			temp.push_back(t);
			if (t == idx)break;
		}
		info.push_back(temp);
		temp.clear();
	}
	return ret;
}
int main() {
	cin >> n;
	v.resize(n);
	cost.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				v[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i])dfs(i);
	}
	int ans = 0;
	for (auto i : info) {
		int minCost = 1000000;
		for (auto j : i) {
			minCost = min(minCost, cost[j]);
		}
		ans += minCost;
	}
	cout << ans;
}