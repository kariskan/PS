#include <iostream>
#include <queue>
using namespace std;

int visit[1000][1000], n, m, map[1000][1000];

int main() {
	
	cin >> n >> m;
	
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				visit[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] != 0) {
				visit[nx][ny] = visit[a][b] + 1;
				q.push({ nx,ny });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j]) {
				cout << visit[i][j] - 1 << ' ';
			}
			else {
				if (map[i][j] == 0)cout << "0 ";
				else cout << "-1 ";
			}
		}
		cout << '\n';
	}
}