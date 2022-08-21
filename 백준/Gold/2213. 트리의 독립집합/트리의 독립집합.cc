#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, w[10001], dp[10001][2]; //i번째 노드를 j==0 선택했을 때, j==1 선택하지 않았을 때 최대 가중치
vector<vector<int>> v;

int dfs(int e, int c, int pre) {
	if (dp[e][c])return dp[e][c];

	int ret = 0;
	if (c == 0) {
		ret = w[e];
	}

	for (auto& i : v[e]) {
		if (i != pre) {
			if (c == 0) {
				ret += dfs(i, 1, e);
			}
			else {
				ret += max(dfs(i, 1, e), dfs(i, 0, e));
			}
		}
	}

	return dp[e][c] = ret;
}

vector<int> answer;

void go(int node, int pre, int c) {

	if (c == 0)answer.push_back(node);

	for (auto& i : v[node]) {
		if (i != pre) {
			if (c == 0) {
				go(i, node, 1);
			}
			else {
				if (dp[i][1] > dp[i][0])go(i, node, 1);
				else go(i, node, 0);
			}
		}
	}
}

int main() {

	cin >> n;
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int ans = max(dfs(1, 0, 0), dfs(1, 1, 0));
	if (dp[1][0] > dp[1][1])go(1, 0, 0);
	else go(1, 0, 1);
	sort(answer.begin(), answer.end());

	cout << ans << '\n';
	for (auto& i : answer)cout << i << ' ';
	return 0;
}