#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n;
int x[8] = { -1,-2,-2,-1,1,2,2,1 };
int y[8] = { 2,1,-1,-2,-2,-1,1,2 };
int sx[4] = { -1,-1,1,1 };
int sy[4] = { -1,1,-1,1 };
int rx[4] = { 1,-1,0,0 };
int ry[4] = { 0,0,1,-1 };
pair<int,int> visit[3][10][10][101];
int board[10][10];
int main() {
	cin >> n;
	queue<tuple<int, int, int, int>> q;
	int ansx, ansy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ 0,i,j,1 });
				q.push({ 1,i,j,1 });
				q.push({ 2,i,j,1 });
				visit[0][i][j][1] = visit[1][i][j][1] = visit[2][i][j][1] = { 1,0 };
			}
			if (board[i][j] == n * n) {
				ansx = i;
				ansy = j;
			}
		}
	}
	pair<int, int>ans = { -1,-1 };
	while (!q.empty()) {
		int a, b, c, d;
		tie(a, b, c, d) = q.front();
		q.pop();
		if (d == n * n) {
			if (ans.first == -1 || ans > visit[a][b][c][d]) {
				ans = visit[a][b][c][d];
			}
		}
		if (a == 0)
			for (int i = 0; i < 8; i++) {
				int nx = b + x[i];
				int ny = c + y[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					int nn = d;
					if (board[nx][ny] == d + 1) {
						nn = d + 1;
					}
					pair<int, int> p = { visit[a][b][c][d].first + 1,visit[a][b][c][d].second };
					if (!visit[a][nx][ny][nn].first || visit[a][nx][ny][nn] > p) {
						visit[a][nx][ny][nn] = p;
						q.push({ a,nx,ny,nn });
					}
				}
			}
		//shop
		else if (a == 1) {
			for (int i = 0; i < 4; i++) {
				for (int j = 1;; j++) {
					int nx = b + j * sx[i];
					int ny = c + j * sy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						int nn = d;
						if (board[nx][ny] == d + 1) {
							nn = d + 1;
						}
						pair<int, int> p = { visit[a][b][c][d].first + 1, visit[a][b][c][d].second };
						if (!visit[a][nx][ny][nn].first || visit[a][nx][ny][nn] > p) {
							visit[a][nx][ny][nn] = p;
							q.push({ a,nx,ny,nn });
						}
					}
					else break;
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				for (int j = 1;; j++) {
					int nx = b + j * rx[i];
					int ny = c + j * ry[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						int nn = d;
						if (board[nx][ny] == d + 1) {
							nn = d + 1;
						}
						pair<int, int> p = { visit[a][b][c][d].first + 1, visit[a][b][c][d].second };
						if (!visit[a][nx][ny][nn].first || visit[a][nx][ny][nn] > p) {
							visit[a][nx][ny][nn] = p;
							q.push({ a,nx,ny,nn });
						}
					}
					else break;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			if (a == i)continue;
			pair<int, int> p = { visit[a][b][c][d].first + 1,visit[a][b][c][d].second + 1 };
			if (!visit[i][b][c][d].first || visit[i][b][c][d] > p) {
				visit[i][b][c][d] = p;
				q.push({ i,b,c,d });
			}
		}
	}
	cout << ans.first - 1 << " " << ans.second;
}