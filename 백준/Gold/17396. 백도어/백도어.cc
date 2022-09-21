#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, wad[100001];
long long dis[100001];
vector<vector<pair<int, long long>>> v;

int main() {
	cin >> n >> m;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> wad[i];
		dis[i] = 2000000000000;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		long long c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	priority_queue<pair<long long, int>> pq;

	dis[0] = 0;
	pq.push({ 0, 0 });

	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (cost > dis[node]) continue;

		for (auto& i : v[node]) {
			if (dis[i.first] > cost + i.second && (!wad[i.first] || i.first == n - 1)) {
				dis[i.first] = cost + i.second;
				pq.push({ -cost - i.second,i.first });
			}
		}
	}

	if (dis[n - 1] != 2000000000000) cout << dis[n - 1];
	else cout << -1;
}