#include <iostream>
#include <queue>
using namespace std;
int visit[500002][2];
int main() {
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>>q;
	q.push({ n,0 });
	visit[n][0] = 1;
	while (!q.empty()) {
		int a, b;
		a = q.front().first;
		b = q.front().second;
		q.pop();
		for (int y : {a + 1, a - 1, a * 2}) {
			if (y >= 0 && y <= 500000 && !visit[y][1 - b]) {
				visit[y][1 - b] = visit[a][b] + 1;
				q.push({ y,1 - b });
			}
		}
	}
	for (int t = 0;; t++) {
		m += t;
		if (m > 500000)break;
		if (visit[m][t % 2] - 1 <= t) {
			cout << t;
			return 0;
		}
	}
	cout << -1;
}