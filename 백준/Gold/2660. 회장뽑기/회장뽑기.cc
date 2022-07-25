#include <iostream>
#include <queue>
using namespace std;

int n, map[51][51], dis[51][51];
int visit[51];
int main() {
	cin >> n;
	while (1) {
		int a, b; cin >> a >> b;
		if (a == -1 && b == -1)break;
		map[a][b] = map[b][a] = 1;
	}
	int ans = 51;
	for (int i = 1; i <= n; i++) {
		queue<int> q;
		q.push(i);
		dis[i][i] = 1;
		int cnt = 0;
		while (!q.empty()) {
			int a = q.front();
			q.pop();

			cnt = max(cnt, dis[i][a] - 1);

			for (int k = 1; k <= n; k++) {
				if (map[a][k] && !dis[i][k]) {
					dis[i][k] = dis[i][a] + 1;
					q.push(k);
				}
			}
		}
		visit[i] = cnt;
		ans = min(ans, cnt);
	}
	int cnt = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == ans) {
			cnt++;
			q.push(i);
		}
	}
	cout << ans << ' ' << cnt << '\n';
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}

}