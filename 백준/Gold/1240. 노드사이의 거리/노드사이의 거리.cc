#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> v;
int ans = 0;
void go(int node, int pre, int cost, int des) {
	if (node == des) {
		ans = cost;
		return;
	}
	for (auto& i : v[node]) {
		if (i.first != pre) {
			go(i.first, node, cost + i.second, des);
		}
	}
}

int main() {
	
	cin >> n >> m;
	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		go(a, 0, 0, b);
		cout << ans << '\n';
		ans = 0;
	}
}