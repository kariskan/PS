#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[1000][1000];
int visit[1000][1000];

int main() {
	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (i == 0 && map[i][j] == '0') {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a == n - 1) {
			cout << "YES";
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] == '0') {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}

	cout << "NO";
}