#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int n, m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int st, de, cost[1001];
vector<vector<pair<int, int>>> map;
int main() {
	cin >> n >> m;
	map.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}
	cin >> st >> de;
	memset(cost, -1, 4 * (n + 1));
	pq.push({ 0, st });
	cost[st] = 0;
	while (!pq.empty()) {
		int a = pq.top().first; //cost
		int b = pq.top().second;//node
		pq.pop();
		if (a > cost[b])continue;
		for (int i = 0; i < map[b].size(); i++) {
			int nx = a + map[b][i].second;
			if (cost[map[b][i].first] == -1 || cost[map[b][i].first] > nx) {
				cost[map[b][i].first] = nx;
				pq.push({ nx, map[b][i].first });
			}
		}
	}
	cout << cost[de];
}