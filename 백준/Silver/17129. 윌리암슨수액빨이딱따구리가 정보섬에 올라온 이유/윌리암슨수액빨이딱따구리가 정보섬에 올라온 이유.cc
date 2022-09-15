#include <iostream>
#include <queue>
using namespace std;
int map[3000][3000], visit[3000][3000];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	queue<pair<int, int>>q;
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			map[i][j] = c - '0';
			if (map[i][j] == 2) {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		if (map[a][b] >= 3 && map[a][b] <= 5) {
			cout << "TAK\n" << visit[a][b] - 1;
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 1 && !visit[nx][ny]) {
				visit[nx][ny] = visit[a][b] + 1;
				q.push({ nx,ny });
			}
		}
	}

	cout << "NIE";
}