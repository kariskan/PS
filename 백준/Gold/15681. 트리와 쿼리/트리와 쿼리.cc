#include <iostream>
#include <vector>
using namespace std;

int n, r, q;
vector<vector<int>> v;
int query[100001], visit[100001];
int go(int node) {
	if (query[node])return query[node];
	int ret = 0;
	visit[node] = 1;
	for (auto& i : v[node]) {
		if (!visit[i]) {
			ret += go(i);
		}
	}
	return query[node] = ret + 1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> r >> q;
	v.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	go(r);
	for (int i = 0; i < q; i++) {
		int u; cin >> u;
		cout << query[u] << '\n';
	}
}