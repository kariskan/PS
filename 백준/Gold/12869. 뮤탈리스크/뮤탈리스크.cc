#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int map[3], visit[61][61][61];

int x[3] = { 9,3,1 };

int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	queue<tuple<int, int, int>> q;
	q.push({ map[0],map[1],map[2] });
	visit[map[0]][map[1]][map[2]] = 1;

	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (i == j || j == k || i == k)continue;
					int na = max(a - x[i], 0);
					int nb = max(b - x[j], 0);
					int nc = max(c - x[k], 0);
					if (visit[na][nb][nc])continue;
					q.push({ na,nb,nc });
					visit[na][nb][nc] = visit[a][b][c] + 1;
				}
			}
		}
	}

	cout << visit[0][0][0] - 1;
}