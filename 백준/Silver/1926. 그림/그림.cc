#include <iostream>
#include <queue>
using namespace std;

int map[500][500];
int visit[500][500];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> q;
	int ansCnt = 0, ansMax = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && map[i][j]) {
				ansCnt++;
				visit[i][j] = 1;
				q.push({ i,j });
				int tempCnt = 0;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					tempCnt++;
					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny]) {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
				ansMax = max(ansMax, tempCnt);
			}
		}
	}
	cout << ansCnt << '\n' << ansMax;
}