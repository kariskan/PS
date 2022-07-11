#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	char map[250][250] = { 0, };
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int visit[250][250] = { 0, };
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '#' && !visit[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = 1;
				int sC = 0, vC = 0;
				while (!q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					if (map[a][b] == 'v')vC++;
					else if (map[a][b] == 'o')sC++;

					for (int k = 0; k < 4; k++) {
						int nx = a + x[k];
						int ny = b + y[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] != '#') {
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
				if (vC >= sC)sC = 0;
				else vC = 0;
				ans1 += sC;
				ans2 += vC;
			}
		}
	}
	cout << ans1 << ' ' << ans2;
}