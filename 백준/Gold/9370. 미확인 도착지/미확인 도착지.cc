#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int T, n, m, t, s, g, h;
vector<vector<pair<int, int>>> v;
vector<int> ans;
int stoa[2001], gtoa[2001], htoa[2001];
void init() {
	ans.clear();
	v.clear();
	memset(stoa, 0, sizeof(stoa));
	memset(gtoa, 0, sizeof(gtoa));
	memset(htoa, 0, sizeof(htoa));
}
void dijk(int no, int dis[]) {
	fill(dis + 1, dis + 1 + n, 987654321);
	priority_queue<pair<int, int>> q;
	dis[no] = 0;
	q.push({ 0,no });

	while (!q.empty()) {
		int node = q.top().second;
		int cost = -q.top().first;
		q.pop();

		if (dis[node] < cost) continue;

		for (auto& i : v[node]) {
			int nxCost = cost + i.second;
			if (dis[i.first] > nxCost) {
				q.push({ -nxCost,i.first });
				dis[i.first] = nxCost;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m >> t >> s >> g >> h;
		v.resize(n + 1);
		vector<int> dis(n + 1, 987654321);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}

		dijk(s, stoa);
		dijk(g, gtoa);
		dijk(h, htoa);

		for (int i = 0; i < t; i++) {
			int query; cin >> query;
			if (min(stoa[g] + htoa[query] + gtoa[h],
				stoa[h] + gtoa[query] + htoa[g]) == stoa[query]) {
				ans.push_back(query);
			}
		}
		
		sort(ans.begin(), ans.end());
		for (auto& i : ans)cout << i << ' ';
		cout << '\n';
		init();
	}
}