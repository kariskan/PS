#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int g[10001], n, m;
vector<vector<int>> v;

int go(int node) {
	queue<int> q;
	int vis[10001] = { 0, };

	q.push(node);
	vis[node] = 1;

	int res = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		res++;

		for (auto& i : v[now]) {
			if (!vis[i]) {
				q.push(i);
				vis[i] = 1;
			}
		}
	}
	return g[node] = res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	int ma = 0;
	for (int i = 1; i <= n; i++) {
		ma = max(ma, go(i));
	}
	for (int i = 1; i <= n; i++) {
		if (g[i] == ma) {
			cout << i << ' ';
		}
	}
}