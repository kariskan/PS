#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, r;
pair<int, int> ans[100001];
vector<vector<int>> v;

int go(int node, int pre, int last) {

	int subSum = 0;

	for (auto& i : v[node]) {
		if (i != pre) {
			subSum += go(i, node, last + subSum * 2 + 1);
		}
	}
	ans[node] = { last + 1, last + 1 + subSum * 2 + 1 };
	return subSum + 1;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v.resize(n + 1);

	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		while (1) {
			int k; cin >> k;
			if (k == -1)break;
			v[t].push_back(k);
		}
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	cin >> r;

	go(r, 0, 0);

	for (int i = 1; i <= n; i++) {
		cout << i << ' ' << ans[i].first << ' ' << ans[i].second << '\n';
	}
}