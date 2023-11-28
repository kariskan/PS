#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
int map[201][201];
int n, k;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				pq.push({ map[i][j],i,j });
			}
		}
	}

	int s, a1, b1;
	cin >> s >> a1 >> b1;

	for (int i = 0; i < s; i++) {
		queue<tuple<int, int, int>> temp;
		while (!pq.empty()) {
			int a, b, c;
			tie(c, a, b) = pq.top();
			pq.pop();

			for (int k = 0; k < 4; k++) {
				int nx = a + x[k];
				int ny = b + y[k];
				if (nx > 0 && nx <= n && ny > 0 && ny <= n && !map[nx][ny]) {
					map[nx][ny] = map[a][b];
					temp.push({ map[a][b],nx,ny });
				}
			}
		}
		while (!temp.empty()) {
			pq.push(temp.front());
			temp.pop();
		}
	}
	cout << map[a1][b1];
}