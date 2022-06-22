#include <iostream>
using namespace std;

int n;
char map[1001][1000];
int visit[1000][1000];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int tSum, tDol;
int ans1, ans2;
void run(int i, int j) {
	tSum++;
	for (int k = 0; k < 4; k++) {
		int nx = i + x[k];
		int ny = j + y[k];
		if (!(nx >= 0 && nx < n && ny >= 0 && ny < n) || map[nx][ny] == '.')tDol++;
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && map[nx][ny] == '#') {
			visit[nx][ny] = 1;
			run(nx, ny);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == '#') {
				visit[i][j] = 1;
				tSum = 0, tDol = 0;
				run(i, j);
				if (tSum >= ans1) {
					if (tSum == ans1 && tDol > ans2) {
						ans2 = tDol;
					}
					else {
						ans1 = tSum;
						ans2 = tDol;
					}

				}
			}
		}
	}
	cout << ans1 << " " << ans2;
}