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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<int> dis(n + 1, 1e9);
	priority_queue<pair<int, int>> pq;

	dis[1] = 0;
	pq.push({ 0,1 });

	int ma = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		ma = max(ma, cost);

		for (auto& i : v[node]) {
			if (dis[i] > cost + 1) {
				dis[i] = cost + 1;
				pq.push({ -(cost + 1),i });
			}
		}
	}

	int f = n + 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] == ma) {
			cnt++;
			f = min(f, i);
		}
	}

	cout << f << ' ' << ma << ' ' << cnt;
}