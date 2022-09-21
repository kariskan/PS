#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, parent[301];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	parent[a] = b;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v.push_back({ a,{0,i} });
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (i != j) {
				v.push_back({ a, {i,j} });
			}
		}
	}

	int ans = 0;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		int p1 = Find(v[i].second.first);
		int p2 = Find(v[i].second.second);

		if (p1 != p2) {
			Union(p1, p2);
			ans += cost;
		}
	}

	cout << ans;

}