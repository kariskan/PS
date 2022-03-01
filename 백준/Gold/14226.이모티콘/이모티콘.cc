#include <iostream>
#include <queue>
using namespace std;
int a;
int visit[1001][1001];
queue<pair<int, int>> q;

int main() {
	cin >> a;
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)visit[i][j] = -1;
	q.push({ 1,0 });
	visit[1][0] = 0;
	while (!q.empty()) {
		int a1, a2;
		a1 = q.front().first;
		a2 = q.front().second;
		q.pop();
		if (visit[a1][a1] == -1) {
			visit[a1][a1] = visit[a1][a2] + 1;
			q.push({ a1,a1 });
		}
		if (a1+a2<= a&&visit[a1 + a2][a2] == -1) {
			visit[a1 + a2][a2] = visit[a1][a2] + 1;
			q.push({ a1 + a2,a2 });
		}
		if (a1 - 1 >= 0 && visit[a1 - 1][a2] == -1) {
			visit[a1 - 1][a2] = visit[a1][a2] + 1;
			q.push({ a1 - 1,a2 });
		}
	}
	int ans = -1;
	for (int i = 0; i <= a; i++) {
		if (visit[a][i] != -1) {
			if (ans == -1 || ans > visit[a][i])ans = visit[a][i];
		}
	}
	cout << ans;
}