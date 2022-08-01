#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, s, d;
int visit[501][501] = { 0, };
vector<int> dis;
vector<vector<pair<int, int>>> stack;
void dijk(vector<vector<pair<int, int>>>& v) {

	priority_queue<pair<int, int>> q;

	dis[s] = 0;
	q.push({ 0,s });

	while (!q.empty()) {
		int node = q.top().second;
		int cost = -q.top().first;
		q.pop();

		if (cost > dis[node]) {
			continue;
		}

		for (auto& i : v[node]) {
			int nxNode = i.first;
			int nxCost = i.second + cost;

			if (nxCost < dis[nxNode]) {
				dis[nxNode] = nxCost;
				q.push({ -nxCost,nxNode });

				stack[nxNode].clear();
				stack[nxNode].push_back({ node,nxCost });
			}
			else if (nxCost == dis[nxNode]) {
				stack[nxNode].push_back({ node,nxCost });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		cin >> s >> d;
		
		vector<vector<pair<int, int>>> v(n);
		dis.resize(n, 987654321);
		stack.resize(n);
		
		for (int i = 0; i < m; i++) {
			int n1, n2, cost;
			cin >> n1 >> n2 >> cost;
			v[n1].push_back({ n2,cost });
		}
		
		dijk(v);

		queue<int> q;
		q.push(d);
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto& i : stack[node]) {
				int nxNode = i.first;
				int nxCost = i.second;

				if (visit[nxNode][node])continue;
				visit[nxNode][node] = 1;

				for (auto& j : v[nxNode]) {
					if (j.first == node) {
						j.second = 987654321;
					}
				}

				q.push(nxNode);
			}
		}

		dis.clear();
		dis.resize(n, 987654321);

		dijk(v);

		if (dis[d] == 987654321) {
			cout << "-1\n";
		}
		else cout << dis[d] << '\n';
		memset(visit, 0, sizeof(visit));
		dis.clear();
		stack.clear();
	}
}