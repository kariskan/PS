#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector < vector<pair<int, int>>> v;
vector<int> dis;
vector<pair<int, int>> ans;
int visit[1001];
void dfs(int node, int sum) {

	for (auto& i : v[node]) {
		if (!visit[i.first] && sum + i.second == dis[i.first]) {
			visit[i.first] = 1;
			ans.push_back({ node,i.first });
			dfs(i.first, sum + i.second);
		}
	}
}

int main() {
	
	cin >> n >> m;
	v.resize(n + 1);
	dis.resize(n + 1, 987654321);

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	priority_queue<pair<int, int>> pq;

	pq.push({ 0,1 });
	dis[1] = 0;

	while (!pq.empty()) {
		int node = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dis[node] < cost) continue;

		for (auto& i : v[node]) {
			int nxNode = i.first;
			int nxCost = cost + i.second;
	
			if (nxCost < dis[nxNode]) {
				pq.push({ -nxCost,nxNode });
				dis[nxNode] = nxCost;
			}
		}
	}
	dfs(1, 0);

	cout << ans.size() << '\n';
	for (auto& i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
}