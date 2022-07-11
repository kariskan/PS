#include <iostream>
#include <deque>
using namespace std;
int n;
int map[50][50], visit[50][50];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a; cin >> a;
			if (a == '1')map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	deque<pair<int, int>> d;
	d.push_back({ 0,0 });
	visit[0][0] = 1;
	while (!d.empty()) {
		int a = d.front().first;
		int b = d.front().second;
		d.pop_front();

		for (int k = 0; k < 4; k++) {
			int nx = a + x[k];
			int ny = b + y[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny]) {
				if (map[nx][ny] == 0) { //검은방
					d.push_back({ nx,ny });
					visit[nx][ny] = visit[a][b] + 1;
				}
				else {
					d.push_front({ nx,ny });
					visit[nx][ny] = visit[a][b];
				}
			}
		}
	}
	cout << visit[n - 1][n - 1] - 1;
}