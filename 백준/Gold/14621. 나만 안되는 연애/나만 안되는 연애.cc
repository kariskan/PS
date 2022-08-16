#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m, sex[1001], parent[1001];
vector<tuple<int, int, int>> v;

int find(int x) {
	if (parent[x] == x)return x;
	return find(parent[x]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b)parent[a] = b;
	else parent[b] = a;
}

int main() {

	cin >> n >> m;
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		char a; cin >> a;
		if (a == 'W')sex[i] = 1;
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ c,a,b });
	}

	sort(v.begin(), v.end());

	int ans = 0;

	for (int i = 0; i < v.size(); i++) {
		int cost, n1, n2;
		tie(cost, n1, n2) = v[i];

		if (sex[n1] != sex[n2] && find(n1) != find(n2)) {
			ans += cost;
			Union(n1, n2);
		}
	}

	for (int i = 1; i < n; i++) {
		if (find(i) != find(i + 1)) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}