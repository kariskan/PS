#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
vector < vector<pair<int, int>>> v;
void dijk(int n, int dis[]) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, n });
	dis[n] = 0;

	while (!q.empty()) {
		int cost = -q.top().first;
		int node = q.top().second;
		q.pop();

		if (dis[node] != -1 && dis[node] < cost) continue;

		for (auto& i : v[node]) {
			int nCost = cost + i.second;
			if (dis[i.first] > nCost || dis[i.first] == -1) {
				dis[i.first] = nCost;
				q.push({ -nCost, i.first });
			}
		}
	}
}
int dis[10001];
int main() {
	int t; cin >> t;
	while (t--) {
		int n, d, c;
		cin >> n >> d >> c;
		v.clear();
		v.resize(n + 1);
		memset(dis, -1, sizeof(dis));
		for (int i = 0; i < d; i++) {
			int a, b, s; cin >> a >> b >> s;
			v[b].push_back({ a,s });
		}
		dijk(c, dis);
		int cnt = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dis[i] != -1) {
				cnt++;
				ans = max(ans, dis[i]);
			}
		}
		cout << cnt << ' ' << ans << '\n';
	}
}