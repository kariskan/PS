#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n;
int x[8] = { -1,-2,-2,-1,1,2,2,1 };
int y[8] = { 2,1,-1,-2,-2,-1,1,2 };
int sx[4] = { -1,-1,1,1 };
int sy[4] = { -1,1,-1,1 };
int visit[3][10][10][101];
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
				visit[0][i][j][1] = visit[1][i][j][1] = visit[2][i][j][1] = 1;
			}
			if (board[i][j] == n * n) {
				ansx = i;
				ansy = j;
			}
		}
	}
	while (!q.empty()) {
		int a, b, c, d;
		tie(a, b, c, d) = q.front();
		q.pop();
		//knight
		if (a == 0) {
			if (!visit[1][b][c][d]) {
				visit[1][b][c][d] = visit[a][b][c][d] + 1;
				q.push({ 1,b,c,d });
			}
			if (!visit[2][b][c][d]) {
				visit[2][b][c][d] = visit[a][b][c][d] + 1;
				q.push({ 2,b,c,d });
			}

		}
		else if (a == 1) {
			if (!visit[0][b][c][d]) {
				visit[0][b][c][d] = visit[a][b][c][d] + 1;
				q.push({ 0,b,c,d });
			}
			if (!visit[2][b][c][d]) {
				visit[2][b][c][d] = visit[a][b][c][d] + 1;
				q.push({ 2,b,c,d });
			}
		}
		else {
			if (!visit[0][b][c][d]) {
				visit[0][b][c][d] = visit[a][b][c][d] + 1;
				q.push({ 0,b,c,d });
			}
			if (!visit[1][b][c][d]) {
				visit[1][b][c][d] = visit[a][b][c][d] + 1;
				q.push({ 1,b,c,d });
			}
		}

		//
		if (a == 0)
			for (int i = 0; i < 8; i++) {
				int nx = b + x[i];
				int ny = c + y[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (board[nx][ny] == d + 1) {
						if (visit[0][nx][ny][d + 1])continue;
						visit[0][nx][ny][d + 1] = visit[a][b][c][d] + 1;
						q.push({ 0,nx,ny,d + 1 });
					}
					else {
						if (visit[0][nx][ny][d])continue;
						visit[0][nx][ny][d] = visit[a][b][c][d] + 1;
						q.push({ 0,nx,ny,d });
					}
				}
			}
		//shop
		if (a == 1)
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < 4; j++) {
					int nx = b + i * sx[j];
					int ny = c + i * sy[j];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						if (board[nx][ny] == d + 1) {
							if (visit[1][nx][ny][d + 1])continue;
							visit[1][nx][ny][d + 1] = visit[a][b][c][d] + 1;
							q.push({ 1,nx,ny,d + 1 });
						}
						else {
							if (visit[1][nx][ny][d])continue;
							visit[1][nx][ny][d] = visit[a][b][c][d] + 1;
							q.push({ 1,nx,ny,d });
						}
					}
				}
			}
		//look
		if (a == 2) {
			for (int i = 1; i <= n; i++) {
				int nx = b;
				int ny = c + i;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (board[nx][ny] == d + 1) {
						if (visit[2][nx][ny][d + 1])continue;
						visit[2][nx][ny][d + 1] = visit[a][b][c][d] + 1;
						q.push({ 2,nx,ny,d + 1 });
					}
					else {
						if (visit[2][nx][ny][d])continue;
						visit[2][nx][ny][d] = visit[a][b][c][d] + 1;
						q.push({ 2,nx,ny,d });
					}
				}
				ny = c - i;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (board[nx][ny] == d + 1) {
						if (visit[2][nx][ny][d + 1])continue;
						visit[2][nx][ny][d + 1] = visit[a][b][c][d] + 1;
						q.push({ 2,nx,ny,d + 1 });
					}
					else {
						if (visit[2][nx][ny][d])continue;
						visit[2][nx][ny][d] = visit[a][b][c][d] + 1;
						q.push({ 2,nx,ny,d });
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				int nx = b + i;
				int ny = c;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (board[nx][ny] == d + 1) {
						if (visit[2][nx][ny][d + 1])continue;
						visit[2][nx][ny][d + 1] = visit[a][b][c][d] + 1;
						q.push({ 2,nx,ny,d + 1 });
					}
					else {
						if (visit[2][nx][ny][d])continue;
						visit[2][nx][ny][d] = visit[a][b][c][d] + 1;
						q.push({ 2,nx,ny,d });
					}
				}
				nx = b - i;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (board[nx][ny] == d + 1) {
						if (visit[2][nx][ny][d + 1])continue;
						visit[2][nx][ny][d + 1] = visit[a][b][c][d] + 1;
						q.push({ 2,nx,ny,d + 1 });
					}
					else {
						if (visit[2][nx][ny][d])continue;
						visit[2][nx][ny][d] = visit[a][b][c][d] + 1;
						q.push({ 2,nx,ny,d });
					}
				}
			}
		}
	}
	int ans = 1000000000;
	if (visit[0][ansx][ansy][n * n] != 0)ans = min(ans, visit[0][ansx][ansy][n * n]);
	if (visit[1][ansx][ansy][n * n] != 0)ans = min(ans, visit[1][ansx][ansy][n * n]);
	if (visit[2][ansx][ansy][n * n] != 0)ans = min(ans, visit[2][ansx][ansy][n * n]);
	cout << ans - 1;
}