#include <iostream>
using namespace std;
int r, c, k,map[1001][1001];
int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };
int main() {
	cin >> c >> r >> k;
	int curX = r;
	int curY = 1;
	int dir = 0;
	int cnt = r * c;
	int num = 1;
	while (cnt--) {
		if (k == num) {
			cout << curY << ' ' << r - curX + 1;
			return 0;
		}
		map[curX][curY] = num++;
		int nx = curX + x[dir];
		int ny = curY + y[dir];
		if (!(nx > 0 && nx <= r && ny > 0 && ny <= c && !map[nx][ny])) {
			dir = (dir + 1) % 4;
			nx = curX + x[dir];
			ny = curY + y[dir];
		}
		curX = nx;
		curY = ny;
	}
	cout << 0;
}