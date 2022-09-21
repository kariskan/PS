#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, c;
int dis[11], ans = -1;
vector<vector<pair<int, int>>> v;

void go(int node, int cost, int su) {

	if (node == b) {
		if (ans == -1 || ans > su) {
			ans = su;
		}
		return;
	}

	for (auto& i : v[node]) {
		if (i.second + cost <= c && i.second + cost < dis[i.first]) {
			int temp = dis[i.first];
			dis[i.first] = i.second + cost;
			go(i.first, i.second + cost, max(su, i.second));
			dis[i.first] = temp;
		}
	}
}

int main() {
	
	cin >> n >> m >> a >> b >> c;
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		dis[i] = 987654321;
	}

	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		v[x].push_back({ y,z });
		v[y].push_back({ x,z });
	}

	dis[a] = 0;
	go(a, 0, 0);

	cout << ans;
}