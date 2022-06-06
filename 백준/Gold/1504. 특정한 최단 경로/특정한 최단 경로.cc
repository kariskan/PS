#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, e;
vector<vector<pair<int, int>>> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int cost[3][801];
int v1, v2;
void run(int idx, int a) {
	cost[idx][a] = 0;
	pq.push({ 0, a });
	while (!pq.empty()) {
		int co = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (cost[idx][node] < co) continue;
		for (int i = 0; i < v[node].size(); i++) {
			int nx = co + v[node][i].second;
			if (cost[idx][v[node][i].first] == -1 || cost[idx][v[node][i].first] > nx) {
				cost[idx][v[node][i].first] = nx;
				pq.push({ nx, v[node][i].first });
			}
		}
	}
}
int main() {
	cin >> n >> e;
	v.resize(n + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	memset(cost, -1, sizeof(cost));
	run(0, 1);
	run(1, v1);
	run(2, v2);
	if (cost[0][v1] != -1 && cost[1][v2] != -1 && cost[2][n] != -1 && cost[0][v2] != -1 && cost[2][v1] != -1 && cost[1][n] != -1)
		cout << min(cost[0][v1] + cost[1][v2] + cost[2][n], cost[0][v2] + cost[2][v1] + cost[1][n]);
	else if (cost[0][v1] != -1 && cost[1][v2] != -1 && cost[2][n] != -1)
		cout << cost[0][v1] + cost[1][v2] + cost[2][n];
	else if (cost[0][v2] != -1 && cost[2][v1] != -1 && cost[1][n] != -1)
		cout << cost[0][v2] + cost[2][v1] + cost[1][n];
	else cout << -1;
}