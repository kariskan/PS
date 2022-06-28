#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, map[100][100], cheeseCount;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int visit[100][100];
int ans1, ans2;
void bfs() {
	queue<pair<int, int>> q;
	vector<pair<int, int>> deleted;
	q.push({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]) {
				if (map[nx][ny] == 1)deleted.push_back({ nx,ny });
				else q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
	if (deleted.size() == cheeseCount) {
		ans2 = deleted.size();
	}
	cheeseCount -= deleted.size();
	for (int i = 0; i < deleted.size(); i++) {
		map[deleted[i].first][deleted[i].second] = 0;
	}
	memset(visit, 0, sizeof(visit));
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j])cheeseCount++;
		}
	}
	while (cheeseCount) {
		bfs();
		ans1++;
	}
	cout << ans1 << "\n" << ans2;
}