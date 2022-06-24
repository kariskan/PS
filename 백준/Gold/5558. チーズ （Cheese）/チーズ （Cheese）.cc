#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int h, w, n;
char map[1001][1001]; //S는 집, 장애물은 X, 공터는 ., 치즈는 1~9
pair<int, int> cheeseCoor[10];
int startX, startY;
int visit[1000][1000];
int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };

int main() {
	cin >> h >> w >> n;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] >= '1' && map[i][j] <= '9') {
				cheeseCoor[map[i][j] - '0'] = {i,j};
			}
			if (map[i][j] == 'S') {
				startX = i;
				startY = j;
			}
		}
	}
	int ans = 0;
	int fromX, fromY, toX, toY;
	for (int i = 1; i <= n; i++) {
		queue<pair<int, int>> q;
		memset(visit, 0, sizeof(visit));
		if (i == 1) {
			fromX = startX, fromY = startY;
		}
		else {
			fromX = toX, fromY = toY;
		}
		toX = cheeseCoor[i].first, toY = cheeseCoor[i].second;
		q.push({ fromX, fromY });
		visit[fromX][fromY] = 1;
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			if (a == toX && b == toY) {
				ans += visit[a][b] - 1;
				break;
			}
			for (int k = 0; k < 4; k++) {
				int nx = a + x[k];
				int ny = b + y[k];
				if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visit[nx][ny] && map[nx][ny] != 'X') {
					visit[nx][ny] = visit[a][b] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	cout << ans;
}