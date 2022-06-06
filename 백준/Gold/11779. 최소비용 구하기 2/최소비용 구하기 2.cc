#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

priority_queue<pair<int, int>> pq; //cost, node, route
int n, m, st, de, cost[1001], r[1001];
vector<vector<pair<int, int>>> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> st >> de;
	pq.push({ 0, st });
	for (int i = 1; i <= n; i++) {
		cost[i] = 987654321;
	}
	cost[st] = 0;
	while (!pq.empty()) {
		int co = -pq.top().first;
		int no = pq.top().second;
		pq.pop();

		if (co > cost[no]) continue;

		for (int i = 0; i < v[no].size(); i++) {
			int no1 = v[no][i].first;
			int co1 = v[no][i].second;
			if (cost[no1] > co + co1) {
				cost[no1] = co + co1;
				r[no1] = no;
				pq.push({ -(co + co1),no1 });
			}
		}
	}
	cout << cost[de] << "\n";
	vector<int> sta;
	while (de != 0) {
		sta.push_back(de);
		de = r[de];
	}
	cout << sta.size() << "\n";
	for (int i = sta.size() - 1; i >= 0; i--)cout << sta[i] << " ";
	return 0;
}