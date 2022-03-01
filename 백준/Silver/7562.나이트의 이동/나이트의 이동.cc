#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int from1, from2, to1, to2;
int map[300][300];
int x[8] = { 1,2,2,1,-1,-2,-2,-1 };
int y[8] = { 2,1,-1,-2,-2,-1,1,2 };
int visit[300][300];
int res[300][300];
int ans = 1000000000;
queue<pair<int, int>> q;
int run() {
	if (from1 == to1 && from2 == to2)return 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = p.first + x[i];
			int nextY = p.second + y[i];
			if (!visit[nextX][nextY] && nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
				if (nextX == to1 && nextY == to2)return res[p.first][p.second] + 1;
				visit[nextX][nextY] = 1;
				res[nextX][nextY] = res[p.first][p.second] + 1;
				q.push({ nextX,nextY });
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> from1 >> from2 >> to1 >> to2;
		q.push({ from1,from2 });
		visit[from1][from2] = 1;
		cout << run() << "\n";
		while (!q.empty())q.pop();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)res[i][j] = visit[i][j] = 0;
		}
	}
}