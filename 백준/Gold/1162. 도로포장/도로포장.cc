#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int n, m, k;
vector<vector<pair<int, long long>>> v;
long long dp[10001][21];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	v.resize(n + 1);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = LLONG_MAX;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	priority_queue<tuple<long long, int, int>> q;
	q.push({ 0,1,0 });
	dp[1][0] = 0;

	while (!q.empty()) {
		long long cost;
		int node, cnt;
		tie(cost, node, cnt) = q.top();
		q.pop();
		cost = -cost;

		if (dp[node][cnt] < cost) continue;

		//dp[i][j] = i정점까지 j개의 도로를 포장해서 오는데 최소 시간

		for (auto& i : v[node]) {
			if (cnt < k) {
				if (dp[i.first][cnt + 1] > cost) {
					dp[i.first][cnt + 1] = cost;
					q.push({ -cost,i.first,cnt + 1 });
				}
			}
			if (dp[i.first][cnt] > cost + i.second) {
				dp[i.first][cnt] = cost + i.second;
				q.push({ -(cost + i.second),i.first,cnt });
			}
		}
	}

	long long ans = -1;

	for (int i = 0; i <= k; i++) {
		if (ans == -1 || ans > dp[n][i]) {
			ans = dp[n][i];
		}
	}

	cout << ans;
}