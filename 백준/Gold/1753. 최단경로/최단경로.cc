#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n, e, k;
vector <vector<pair<int, int>>> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int cost[20001];

int main() {
	cin >> n >> e >> k;
	v.resize(n + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	pq.push({ 0,k });
	memset(cost, -1, sizeof(cost));
	cost[k] = 0;
	while (!pq.empty()) {
		int a = pq.top().first;
		int b = pq.top().second;
		pq.pop();
		if (a > cost[b]) continue;
		for (int i = 0; i < v[b].size(); i++) {
			int nx = a + v[b][i].second;
			if (cost[v[b][i].first] == -1 || cost[v[b][i].first] > nx) {
				cost[v[b][i].first] = nx;
				pq.push({ nx, v[b][i].first });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cost[i] == -1)cout << "INF\n";
		else cout << cost[i] << "\n";
	}
}