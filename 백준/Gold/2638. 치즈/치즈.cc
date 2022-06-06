#include <iostream>
#include <queue>
using namespace std;
int map[100][100], n, m;
bool out[100][100];
queue<pair<int, int>> q;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
void outside() {
	int visit[100][100] = { 0, };
	q.push({ 0, 0 });
	visit[0][0] = 1;
	out[0][0] = true;
	while (!q.empty()) {
		int a, b;
		a = q.front().first;
		b = q.front().second;
		q.pop();
		out[a][b] = true;
		for (int i = 0; i < 4; i++) {
			int nx = a + x[i];
			int ny = b + y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] != 1) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j])cnt++;
		}
	}
	outside();
	int ans = 0;
	while (cnt) {
		queue<pair<int, int>> t;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					int outCnt = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + x[k];
						int ny = j + y[k];
						if (out[nx][ny])outCnt++;
					}
					if (outCnt >= 2) {
						t.push({ i,j });
						cnt--;
					}
				}
			}
		}
		while (!t.empty()) {
			map[t.front().first][t.front().second] = 0;
			out[t.front().first][t.front().second] = true;
			t.pop();
		}
		outside();
		ans++;
	}
	cout << ans;
	return 0;
}