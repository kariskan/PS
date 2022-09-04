#include <iostream>
#include <queue>
using namespace std;

int n, k, map[2000][2000], p[100001], visit[2000][2000];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
queue<pair<int, int>> u, q;

bool range(int nx, int ny) {
	return nx >= 0 && nx < n && ny >= 0 && ny < n;
}

int Find(int a) {
	if (a == p[a])return a;
	else return p[a] = Find(p[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a < b)p[b] = a;
	else p[a] = b;
}

void go() {

	while (!u.empty()) {
		int a = u.front().first;
		int b = u.front().second;
		q.push({ a,b });
		u.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + x[i];
			int ny = b + y[i];
			if (range(nx, ny) && map[nx][ny] && map[nx][ny] != map[a][b] && Find(map[nx][ny]) != Find(map[a][b])) {
				Union(map[nx][ny], map[a][b]);
				k--;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		p[i] = i;
	}

	for (int i = 1; i <= k; i++) {
		int a, b; cin >> a >> b;
		map[n - b][a - 1] = i;
		u.push({ n - b,a - 1 });
	}

	k--;

	for (int t = 0;; t++) {

		go();

		if (!k) {
			cout << t;
			return 0;
		}

		while (!q.empty()) {

			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = a + x[i];
				int ny = b + y[i];
				if (range(nx, ny) && !map[nx][ny]) {
					u.push({ nx,ny });
					map[nx][ny] = map[a][b];
				}
			}
		}
	}
}