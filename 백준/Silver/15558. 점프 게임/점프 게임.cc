#include <iostream>
#include <queue>
using namespace std;
int board[2][200002];
int visit[2][200002];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	queue<pair<int, int>>q;
	q.push({ 0,1 });
	visit[0][1] = 1;
	while (!q.empty()) {
		int a, b;
		a = q.front().first;
		b = q.front().second;
		q.pop();
		if (b > n) {
			cout << 1;
			return 0;
		}
		if ((board[a][b + 1] == 1 || b + 1 > n) && !visit[a][b + 1]) {
			q.push({ a,b + 1 });
			visit[a][b + 1] = visit[a][b] + 1;
		}
		if (b>0&&board[a][b - 1] == 1 && visit[a][b] < b - 1 && !visit[a][b-1]) {
			q.push({ a,b - 1 });
			visit[a][b - 1] = visit[a][b] + 1;
		}
		if ((board[1 - a][b + k] == 1 || b + k > n) && !visit[1 - a][b + k]) {
			q.push({ 1 - a,b + k });
			visit[1 - a][b + k] = visit[a][b] + 1;
		}
	}
	cout << 0;
}