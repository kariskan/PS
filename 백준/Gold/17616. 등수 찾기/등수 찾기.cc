#include <iostream>
#include <vector>
using namespace std;

int n, m, x;

int go(int node, vector<vector<int>>& v, int visit[100001]) {
	visit[node] = 1;

	int ret = 0;
	for (auto& i : v[node]) {
		if (!visit[i]) {
			ret += go(i, v, visit);
		}
	}
	return ret + 1;
}

int main() {

	cin >> n >> m >> x;
	vector<vector<int>> v(n + 1), rev(n + 1);
	int visit[100001] = { 0, }, visit2[100001] = { 0, };

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		rev[b].push_back(a);
	}

	int cnt = go(x, v, visit) - 1;
	int revCnt = go(x, rev, visit2);

	cout << revCnt << ' ' << n - cnt;
}