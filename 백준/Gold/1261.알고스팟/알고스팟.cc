#include <iostream>
#include <deque>
using namespace std;
int a, b;
deque<pair<int, int>> q;
int brk;
int visit[100][100];
int map[100][100];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
void run() {
	while (!q.empty()) {
		int k1 = q.front().first;
		int k2 = q.front().second;
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x[i] + k1;
			int ny = y[i] + k2;
			if (nx >= 0 && nx < b && ny >= 0 && ny < a && visit[nx][ny] == -1) {
				if (map[nx][ny] == 0) {
					q.push_front({nx, ny});
					visit[nx][ny] = visit[k1][k2];
				}
				else {
					q.push_back({ nx,ny });
					visit[nx][ny] = visit[k1][k2] + 1;
				}
			}
		}
	}
}
int main() {
	cin >> a >> b;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	q.push_front({ 0,0 });
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			visit[i][j] = -1;
		}
	}
	visit[0][0] = 0;
	run();
	cout << visit[b - 1][a - 1];
}