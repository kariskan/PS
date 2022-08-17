#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int parent[1001];
vector<tuple<int, int, int>> v;

int Find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a < b)parent[a] = b;
	else parent[b] = a;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			if (j > i)v.push_back({ a,i,j });
		}
	}

	sort(v.begin(), v.end());

	long long ans = 0;

	for (int i = 0; i < v.size(); i++) {
		int cost, n1, n2;
		tie(cost, n1, n2) = v[i];

		if (Find(n1) != Find(n2)) {
			Union(n1, n2);
			ans += cost;
		}
	}

	cout << ans;
}