#include <iostream>
#include <queue>
using namespace std;
int map[65][65], visit[65][65];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	queue<pair<int, int>>q;
	int x[2] = { 0,1 };
	int y[2] = { 1,0 };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	q.push({ 1,1 });
	visit[1][1] = 1;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int k = 0; k < 2; k++) {
			int nx = a + x[k] * map[a][b];
			int ny = b + y[k] * map[a][b];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}

	if (visit[n][n])cout << "HaruHaru";
	else cout << "Hing";
}