#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
int visit[4][50][50][4];
int main() {
	int n, m;
	cin >> n >> m;
	char s[51][50];
	int sx1 = -1, sy1, sx2, sy2;
	queue<tuple<int, int, int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
			if (s[i][j] == 'S') {
				q.push({ -1,i,j,0 });
			}
			if (s[i][j] == 'C') {
				if (sx1 == -1) {
					sx1 = i;
					sy1 = j;
				}
				else {
					sx2 = i;
					sy2 = j;
				}
			}
		}
	}
	int ans = -1;
	while (!q.empty()) {
		int a, b, c, d;
		tie(a, b, c, d) = q.front();
		q.pop();
		if (d == 3) {
			ans = visit[a][b][c][d];
			break;
		}
		for (int i = 0; i < 4; i++) {
			if (a == i && a != -1)continue;
			int nx = b + x[i];
			int ny = c + y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != '#') {
				int k = d;
				if (s[nx][ny] == 'C') {
					if (sx1 == nx && sy1 == ny) {
						k |= 1;
					}
					else {
						k |= 2;
					}
				}
				if (!visit[i][nx][ny][k]) {
					if (a == -1)visit[i][nx][ny][k] = 1;
					else visit[i][nx][ny][k] = visit[a][b][c][d] + 1;
					q.push({ i,nx,ny,k });
				}
			}
		}
	}
	cout << ans;
}