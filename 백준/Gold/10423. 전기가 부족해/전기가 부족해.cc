#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k, parent[1001], y[1001];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a < b) parent[a] = b;
	else parent[b] = a;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		parent[a] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}

	sort(v.begin(), v.end());
	int ans = 0;

	for (auto& i : v) {
		int n1 = i.second.first;
		int n2 = i.second.second;
		int cost = i.first;

		int f1 = Find(n1);
		int f2 = Find(n2);

		if (f1 != f2) {
			Union(n1, n2);
			ans += cost;
		}
	}

	cout << ans;
}