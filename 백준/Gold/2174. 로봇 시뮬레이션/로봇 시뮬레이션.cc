#include <iostream>
using namespace std;
typedef struct state{
	int x;
	int y;
	int dir;
};
int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };
int a, b, n, m;
state robot[101];
int main() {
	cin >> b >> a >> n >> m;
	for (int i = 1; i <= n; i++) {
		int ta, tb, tc;
		char c;
		cin >> tb >> ta >> c;
		if (c == 'E') {
			tc = 0;
		}
		else if (c == 'S') {
			tc = 1;
		}
		else if (c == 'W') {
			tc = 2;
		}
		else {
			tc = 3;
		}
		robot[i] = { a - ta + 1,tb,tc };
	}
	for (int i = 1; i <= m; i++) {
		int robotNum, cmdCount;
		char cmd;
		cin >> robotNum >> cmd >> cmdCount;
		for (int j = 1; j <= cmdCount; j++) {
			if (cmd == 'L') {
				if (robot[robotNum].dir == 0)robot[robotNum].dir = 3;
				else robot[robotNum].dir--;
			}
			else if (cmd == 'R') {
				robot[robotNum].dir = (robot[robotNum].dir + 1) % 4;
			}
			else {
				int nx = robot[robotNum].x + x[robot[robotNum].dir];
				int ny = robot[robotNum].y + y[robot[robotNum].dir];
				if (!(nx > 0 && nx <= a && ny > 0 && ny <= b)) {
					cout << "Robot " << robotNum << " crashes into the wall";
					return 0;
				}
				for (int k = 1; k <= n; k++) {
					if (robotNum == k)continue;
					if (nx == robot[k].x && ny == robot[k].y) {
						cout << "Robot " << robotNum << " crashes into robot " << k;
						return 0;
					}
				}
				robot[robotNum].x = nx;
				robot[robotNum].y = ny;
			}
		}
	}
	cout << "OK";
}