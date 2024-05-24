#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, e, k;
	cin >> n >> e >> k;

	vector<vector<pair<int, int>>> v(n + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	vector<int> dis(n + 1, 1e9);
	priority_queue<pair<int, int>> pq;

	dis[k] = 0;
	pq.push({ 0,k });

	while (!pq.empty()) {
		int node = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dis[node] < cost) {
			continue;
		}

		for (auto& i : v[node]) {
			int nxNode = i.first;
			int nxCost = cost + i.second;
			if (nxCost < dis[nxNode]) {
				dis[nxNode] = nxCost;
				pq.push({ -nxCost,nxNode });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dis[i] == 1e9) {
			cout << "INF\n";
		}
		else {
			cout << dis[i] << '\n';
		}
	}
}