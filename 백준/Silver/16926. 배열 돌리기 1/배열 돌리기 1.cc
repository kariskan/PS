#include <iostream>
using namespace std;

int n, m, r;
int map[300][300];
int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };
int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int cnt = 0; cnt < r; cnt++) {
		for (int i = 0; i < (min(n, m) + 1) / 2; i++) {
			int dir = 0;
			int preX = i;
			int preY = i;
			int curX = i + x[dir];
			int curY = i + y[dir];
			int elem = map[i][i];
			int preElem = map[i][i];
			while (1) {
				elem = map[curX][curY];
				map[curX][curY] = preElem;
				if (curX == i && curY == i)break;
				preX = curX;
				preY = curY;
				
				int nx = curX + x[dir];
				int ny = curY + y[dir];
				if (!(nx >= i && nx <= n - i - 1 && ny >= i && ny <= m - i - 1)) {
					dir++;
					nx = curX + x[dir];
					ny = curY + y[dir];
				}
				curX = nx;
				curY = ny;
				preElem = elem;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}