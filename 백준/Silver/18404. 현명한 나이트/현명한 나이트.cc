#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int x[8] = { -2,-1,1,2,2,1,-1,-2 };
int y[8] = { 1,2,2,1,-1,-2,-2,-1 };
int visit[501][501];
pair<int, int> map[1000];

int n, m, kx, ky;

int main() {
	cin >> n >> m >> kx >> ky;

	for (int i = 0; i < m; i++) {
		int A, B; cin >> A >> B;
		map[i] = { A,B };
	}

	queue<pair<int, int>> q;

	visit[kx][ky] = 1;
	q.push({ kx,ky });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n && !visit[nx][ny]) {
				visit[nx][ny] = visit[a][b] + 1;
				q.push({ nx,ny });
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << visit[map[i].first][map[i].second] - 1 << ' ';
	}
}