#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int x[4] = { -1,0,0,1 };
int y[4] = { 0,-1,1,0 };
int board[20][20];
int visit[20][20];
int n;
int sX, sY, dis;
int SIZE = 2, EXP;
queue<pair<int, int>> q; //x, y

int bfs() {
	vector<tuple<int, int, int>>v;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny]) {
				if (board[nx][ny] == 0) {
					visit[nx][ny] = visit[a][b] + 1;
					q.push({ nx,ny });
				}
				else {
					if (board[nx][ny] > SIZE) continue;
					else if (board[nx][ny] < SIZE) v.push_back({ visit[a][b],nx,ny });
					visit[nx][ny] = visit[a][b] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (v.empty())return 0;
	EXP++;
	if (EXP == SIZE) {
		EXP = 0;
		SIZE++;
	}
	sort(v.begin(), v.end());
	tie(dis, sX, sY) = v.front();
	board[sX][sY] = 0;
	return visit[sX][sY];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				sX = i; sY = j;
				board[i][j] = 0;
			}
		}
	}

	int ans = 0;
	while (1) {
		visit[sX][sY] = 1;
		q.push({ sX,sY });
		int temp = bfs() - 1;
		if (temp == -1)break;
		ans += temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = 0;
			}
		}
	}
	cout << ans;
}