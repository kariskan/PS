#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int n, m, map[51][51], erased[51][51];
int ddx[4] = { -1,-1,1,1 };
int ddy[4] = { -1,1,-1,1 };

queue<pair<int, int>> cloud;
queue<pair<int, int>> dup;

void moveCloud(int d, int s) {

	int siz = cloud.size();

	for (int i = 0; i < siz; i++) {

		int x = cloud.front().first;
		int y = cloud.front().second;
		cloud.pop();

		for (int i = 0; i < s; i++) {
			x += dx[d];
			y += dy[d];
			if (x == 0)x = n;
			else if (x == n + 1) x = 1;
			if (y == 0)y = n;
			else if (y == n + 1) y = 1;
		}

		cloud.push({ x,y });
	}
}

void rain() {
	while (!cloud.empty()) {

		int x = cloud.front().first;
		int y = cloud.front().second;
		cloud.pop();

		map[x][y]++;
		erased[x][y] = 1;
		dup.push({ x,y });
	}
}

void dupli() {
	queue<pair<pair<int, int>, int>> q;
	while (!dup.empty()) {
		int x = dup.front().first;
		int y = dup.front().second;
		dup.pop();

		int basketCnt = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + ddx[i];
			int ny = y + ddy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n && map[nx][ny]) {
				basketCnt++;
			}
		}

		q.push({ {x,y},basketCnt });
	}

	while (!q.empty()) {
		map[q.front().first.first][q.front().first.second] += q.front().second;
		q.pop();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] >= 2 && !erased[i][j]) {
				cloud.push({ i,j });
				map[i][j] -= 2;
			}
		}
	}

	memset(erased, 0, sizeof(erased));
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	cloud.push({ n,1 });
	cloud.push({ n,2 });
	cloud.push({ n - 1,1 });
	cloud.push({ n - 1,2 });

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		moveCloud(a, b);
		rain();
		dupli();
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += map[i][j];
		}
	}

	cout << ans;
}