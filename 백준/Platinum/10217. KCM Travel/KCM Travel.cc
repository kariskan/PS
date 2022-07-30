#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef struct N{
	int des;
	int cost;
	int time;

	bool operator<(const N& data)const {
		return cost < data.cost;
	}
}node;

int dp[101][10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<node>> info(n + 1);
		for (int i = 0; i < k; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			info[u].push_back({ v,c,d });
		}
		priority_queue<node> q;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				dp[i][j] = 987654321;
			}
		}
		q.push({ 1,0,0 });
		dp[1][0] = 0;

		while (!q.empty()) {
			node Node = q.top();
			int now = Node.des;
			int cost = -Node.cost;
			int Time = Node.time;
			q.pop();

			if (dp[now][cost] < Time) continue;

			for (auto& i : info[now]) {
				int nxNode = i.des;
				int nxCost = i.cost + cost;
				int nxTime = i.time + dp[now][cost];

				if (nxCost > m) continue;
				if (dp[nxNode][nxCost] <= nxTime)continue;
				dp[nxNode][nxCost] = nxTime;
				q.push({ nxNode,-nxCost,nxTime });
			}
		}
		int ans = -1;
		for (int i = 0; i <= m; i++) {
			if (dp[n][i] == 987654321)continue;
			if (ans == -1 || ans > dp[n][i])ans = dp[n][i];
		}
		if (ans == -1)cout << "Poor KCM\n";
		else cout << ans << "\n";
		memset(dp, 0, sizeof(dp));
	}
}