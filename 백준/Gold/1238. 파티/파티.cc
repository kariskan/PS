#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n, m, x;
int cost[1001][1001];
vector<vector<pair<int, int>>> v;
void dijkstra(int idx) {
	priority_queue<pair<int, int>> pq;
	pq.push({ idx, 0 });
	while (!pq.empty()) {
		int a = pq.top().first; //node
		int b = -pq.top().second;//cost
		pq.pop();

		if (b != -1 && cost[idx][a] < b)continue;
		for (int i = 0; i < v[a].size(); i++) {
			int nx = b + v[a][i].second;
			if (cost[idx][v[a][i].first] == -1 || cost[idx][v[a][i].first] > nx) {
				cost[idx][v[a][i].first] = nx;
				pq.push({ v[a][i].first, -nx });
			}
		}
	}
}
int main() {
	cin >> n >> m >> x;
	v.resize(n + 1);
	memset(cost, -1, sizeof(cost));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++) {
		cost[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (ans == -1 || ans < cost[x][i] + cost[i][x]) {
			ans = cost[x][i] + cost[i][x];
		}
	}
	cout << ans;
}