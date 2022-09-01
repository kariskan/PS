#include <iostream>
using namespace std;

int n, m, k, map[101][101], cw[101][101], ccw[101][101];
int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };
pair<int, int> inp[100];

bool ok(int x, int y) {
	return x >= 0 && x <= n && y >= 0 && y <= m;
}

int changeCW(int dir) {
	return (dir + 1) % 4;
}

int changeCCW(int dir) {
	return (dir + 3) % 4;
}

void get(int sx, int sy, int c, int dir) {

	int cnt = 0;
	int dx = sx, dy = sy;

	while (1) {

		dx += x[dir];
		dy += y[dir];
		cnt++;

		if (!ok(dx, dy)) {
			dx -= x[dir];
			dy -= y[dir];
			if (c == 0)dir = changeCW(dir);
			else dir = changeCCW(dir);
			dx += x[dir];
			dy += y[dir];
		}

		if (map[dx][dy]) {
			if (c == 0)cw[dx][dy] = cnt;
			else ccw[dx][dy] = cnt;
		}

		if (dx == sx && dy == sy)break;
	}
}

int main() {
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			map[0][b] = 1;
			inp[i] = { 0,b };
		}
		else if (a == 2) {
			map[n][b] = 1;
			inp[i] = { n,b };
		}
		else if (a == 3) {
			map[b][0] = 1;
			inp[i] = { b,0 };
		}
		else {
			map[b][m] = 1;
			inp[i] = { b,m };
		}
	}

	int dx, dy, dir, cwdir;
	cin >> dx >> dy;
	if (dx == 1) {
		dx = 0;
		dir = 0;
		cwdir = 2;
	}
	else if (dx == 2) {
		dx = n;
		dir = 2;
		cwdir = 0;
	}
	else if (dx == 3) {
		dx = dy;
		dy = 0;
		dir = 3;
		cwdir = 1;
	}
	else {
		dx = dy;
		dy = m;
		dir = 1;
		cwdir = 3;
	}

	get(dx, dy, 0, dir);
	get(dx, dy, 1, cwdir);

	int ans = 0;

	for (int i = 0; i < k; i++) {
		ans += min(cw[inp[i].first][inp[i].second], ccw[inp[i].first][inp[i].second]);
	}

	cout << ans;
}