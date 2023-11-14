#include <iostream>
using namespace std;
int r, c, k;
char map[6][6];
int visit[6][6];
int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
int ans;
void run(int i, int j, int sum) {
	if (sum > k)return;
	if (i == 0 && j == c - 1 && sum == k) {
		ans++;
		return;
	}
	for (int l = 0; l < 4; l++) {
		int nx = i + x[l];
		int ny = j + y[l];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visit[nx][ny] && map[nx][ny] != 'T') {
			visit[nx][ny] = 1;
			run(nx, ny, sum + 1);
			visit[nx][ny] = 0;
		}
	}
}
int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	visit[r - 1][0] = 1;
	run(r - 1, 0, 1);
	cout << ans;
}