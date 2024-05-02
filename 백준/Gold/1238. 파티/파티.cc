#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<pair<int, int>>> v(n + 1), rev(n + 1);
	vector<int> dis(n + 1, 1e9), revDis(n + 1, 1e9);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		rev[b].push_back({ a,c });
	}

	priority_queue<pair<int, int>> pq;

	pq.push({ 0,x });
	dis[x] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (pair<int, int> nxt : v[node]) {
			int nxCost = cost + nxt.second;
			if (nxCost < dis[nxt.first]) {
				dis[nxt.first] = nxCost;
				pq.push({ -nxCost,nxt.first });
			}
		}
	}

	pq.push({ 0,x });
	revDis[x] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (pair<int, int> nxt : rev[node]) {
			int nxCost = cost + nxt.second;
			if (nxCost < revDis[nxt.first]) {
				revDis[nxt.first] = nxCost;
				pq.push({ -nxCost,nxt.first });
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) {
			continue;
		}
		answer = max(answer, dis[i] + revDis[i]);
	}
	cout << answer;
}