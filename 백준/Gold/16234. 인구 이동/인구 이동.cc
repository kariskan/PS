#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, l, r;
int map[50][50], visit[50][50];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

int main() {

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (;; ans++) {
		bool ok = false;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j]) {

					vector<pair<int, int>> v;
					queue<pair<int, int>> q;

					v.push_back({ i,j });
					q.push({ i,j });
					visit[i][j] = 1;
					int sum = map[i][j];

					while (!q.empty()) {
						int a = q.front().first;
						int b = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++) {
							int nx = a + x[k];
							int ny = b + y[k];
							if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && abs(map[a][b] - map[nx][ny]) >= l && abs(map[a][b] - map[nx][ny]) <= r) {
								v.push_back({ nx,ny });
								q.push({ nx,ny });
								visit[nx][ny] = 1;
								sum += map[nx][ny];
							}
						}
					}

					if (v.size() != 1) {
						ok = true;
						int t = sum / v.size();
						for (int k = 0; k < v.size(); k++) {
							map[v[k].first][v[k].second] = t;
						}
					}
				}
			}
		}
		if (!ok)break;
	}
	cout << ans;
}