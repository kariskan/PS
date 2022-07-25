#include <iostream>
using namespace std;

int n, m, visit[100][100];
char map[100][100];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int cnt = 0;
void go(int i, int j) {
	cnt++;
	for (int k = 0; k < 4; k++) {
		int nx = i + x[k];
		int ny = j + y[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[i][j] == map[nx][ny]) {
			visit[nx][ny] = visit[i][j] + 1;
			go(nx, ny);
		}
	}
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int w = 0, b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				visit[i][j] = 1;
				go(i, j);
				if (map[i][j] == 'W') {
					w += cnt * cnt;
				}
				else {
					b += cnt * cnt;
				}
				cnt = 0;
			}
		}
	}
	cout << w << ' ' << b;
}