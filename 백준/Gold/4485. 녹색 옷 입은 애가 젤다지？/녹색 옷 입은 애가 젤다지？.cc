#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int map[125][125];
int n;
int main() {
	for (int num = 1;; num++) {
		cin >> n;
		if (!n)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		vector<vector<int>> dis(n,vector<int>(n, 987654321));
		dis[0][0] = map[0][0];
		priority_queue<tuple<int, int, int>> pq;
		pq.push({ 0,0,-dis[0][0] });
		while (!pq.empty()) {
			int st, de, cost;
			tie(st, de, cost) = pq.top();
			pq.pop();
			cost = -cost;

			if (dis[st][de] < cost) continue;

			for(int k = 0; k < 4; k++) {
				int nx = st + x[k];
				int ny = de + y[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					int nCost = cost + map[nx][ny];
					if (dis[nx][ny] > nCost) {
						pq.push({ nx,ny,-nCost });
						dis[nx][ny] = nCost;
					}
				}
			}
		}

		cout << "Problem " << num << ": " << dis[n - 1][n - 1] << '\n';
	}
}