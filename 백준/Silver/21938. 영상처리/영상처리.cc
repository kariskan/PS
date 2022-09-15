#include <iostream>
#include <queue>
using namespace std;

int ar[3][1000][1000], visit[1000][1000];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> ar[k][i][j];
			}
		}
	}

	int t; cin >> t;

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ar[0][i][j] + ar[1][i][j] + ar[2][i][j] >= 3 * t) {
				ar[0][i][j] = 255;
			}
			else {
				ar[0][i][j] = 0;
			}
		}
	}

	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && ar[0][i][j] == 255) {
				visit[i][j] = 1;
				q.push({ i,j });
				ans++;

				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && ar[0][nx][ny] == 255) {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}

	cout << ans;
}