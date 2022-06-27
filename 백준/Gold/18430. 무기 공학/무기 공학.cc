#include <iostream>
using namespace std;

int n, m;
int map[5][5], visit[5][5];

int x[4][3] = { {0,0,1},{-1,0,0},{-1,0,0},{0,0,1} };
int y[4][3] = { {-1,0,0},{0,0,-1},{0,0,1},{1,0,0} };
int ans;
void go(int i, int j, int sum) {
	ans = max(ans, sum);
	for (int i1 = i; i1 < n; i1++) {
		for (int j1 = 0; j1 < m; j1++) {
			if ((i1 == i && j1 < j) || visit[i1][j1])continue;
			for (int k = 0; k < 4; k++) {
				int temp = sum;
				bool ok = true;
				for (int l = 0; l < 3; l++) {
					int nx = i1 + x[k][l];
					int ny = j1 + y[k][l];
					if (!(nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny])) {
						ok = false;
						break;
					}
				}
				if (ok) {
					for (int l = 0; l < 3; l++) {
						int nx = i1 + x[k][l];
						int ny = j1 + y[k][l];
						visit[nx][ny] = 1;
						if (l == 1)temp += map[nx][ny] * 2;
						else temp += map[nx][ny];
					}
					go(i1, j1, temp);
					for (int l = 0; l < 3; l++) {
						int nx = i1 + x[k][l];
						int ny = j1 + y[k][l];
						visit[nx][ny] = 0;
					}
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	go(0, 0, 0);
	cout << ans;
}