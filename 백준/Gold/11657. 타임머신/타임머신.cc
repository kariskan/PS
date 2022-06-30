#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
long long visit[501];
long long edge[6000][3];
int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
	}
	
	for (int i = 1; i <= n; i++)visit[i] = INT64_MAX;
	visit[1] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < m; j++) {
			long long from = edge[j][0];
			long long to = edge[j][1];
			long long cost = edge[j][2];
			if (visit[from] == INT64_MAX)continue;
			if (visit[to] > visit[from] + cost) {
				visit[to] = visit[from] + cost;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		long long from = edge[j][0];
		long long to = edge[j][1];
		long long cost = edge[j][2];
		if (visit[from] == INT64_MAX)continue;
		if ( visit[to] > visit[from] + cost) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (visit[i] == INT64_MAX)cout << -1 << '\n';
		else cout << visit[i] << '\n';
	}
}