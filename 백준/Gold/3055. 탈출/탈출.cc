#include <iostream>
#include <queue>
using namespace std;
int n, m;
char map[50][50];
int visit[50][50];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;
void expand() {
	queue<pair<int, int>> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '*') {
				t.push({ i,j });
			}
		}
	}
	while (!t.empty()) {
		int a = t.front().first;
		int b = t.front().second;
		t.pop();

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 'X' && map[nx][ny] != 'D') {
				map[nx][ny] = '*';
			}
		}
	}
}

void move() {
	queue<pair<int, int>> temp;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] != '*' && map[nx][ny] != 'X') {
				visit[nx][ny] = visit[a][b] + 1;
				temp.push({ nx,ny });
			}
		}
	}
	while (!temp.empty()) {
		q.push(temp.front());
		temp.pop();
	}
}

int main() {
	cin >> n >> m;
	int r, c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') {
				r = i;
				c = j;
			}
			if (map[i][j] == 'S') {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}
	while (1) {
		expand();
		move();
		if (q.empty()) break;
	}
	if (visit[r][c] == 0)cout << "KAKTUS";
	else cout << visit[r][c] - 1;
}