#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v;
int num[10001], dp[10001][2];
int ans;
int dfs(int node, int pre, int cnt) {
	if (dp[node][cnt])return dp[node][cnt];

	int ret = 0;
	if (cnt)ret = num[node];

	for (auto& i : v[node]) {

		if (i != pre) {
			int no = dfs(i, node, 0);
			int yes = dfs(i, node, 1);
			if (cnt == 1) {
				ret += no;
			}
			else {
				ret += max(no, yes);
			}
		}
	}

	return dp[node][cnt] = ret;
}

int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	cout << max(dfs(1, 0, 0), dfs(1, 0, 1));
}