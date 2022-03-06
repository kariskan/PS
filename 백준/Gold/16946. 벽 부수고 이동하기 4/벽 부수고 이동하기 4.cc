#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int visit[1000][1000];
int board[1000][1000];
int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 && !visit[i][j]) {
				q.push({ i,j });
				visit[i][j] = 1;
				int ma = 1;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if (board[nx][ny] == 1) {
								v.push_back({ nx,ny });
							}
							else {
								if (!visit[nx][ny]) {
									visit[nx][ny] = 1;
									ma++;
									q.push({ nx,ny });
								}
							}
						}
					}
				}
				sort(v.begin(), v.end());
				v.erase(unique(v.begin(), v.end()), v.end());
				while (!v.empty()) {
					int a = v.back().first;
					int b = v.back().second;
					visit[a][b] = (visit[a][b] % 10 + ma % 10) % 10;
					v.pop_back();
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0)cout << 0;
			else cout << (visit[i][j] + 1) % 10;
		}
		cout << "\n";
	}
}