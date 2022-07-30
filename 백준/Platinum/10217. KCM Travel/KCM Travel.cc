#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<pair<pair<int, int>, int>>> info(n + 1);
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 987654321));
		for (int i = 0; i < k; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			info[u].push_back({ {c,d},v });
		}
		priority_queue<pair<pair<int, int>, int>> q;
		q.push({ {0,0},1 });
		dp[1][0] = 0;
		int ok = 0;
		while (!q.empty()) {
			int now = q.top().second;
			int cost = -q.top().first.second;
			int Time = -q.top().first.first;
			q.pop();

			if (dp[now][cost] < Time || cost > m) continue;
			if (now == n) {
				cout << Time << '\n';
				ok = 1;
				break;
			}

			for (auto& i : info[now]) {
				int nxNode = i.second;
				int nxCost = i.first.first + cost;
				int nxTime = i.first.second + Time;

				if (nxCost > m) continue;
				if (dp[nxNode][nxCost] <= nxTime)continue;
				dp[nxNode][nxCost] = nxTime;
				q.push({ {-nxTime,-nxCost},nxNode });
			}
		}
		if (!ok)cout << "Poor KCM\n";
	}
}