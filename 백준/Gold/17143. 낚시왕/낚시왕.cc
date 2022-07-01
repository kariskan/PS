#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct shark {
	int speed;
	int dir;
	int size;
};

int R, C, M;
shark map[102][102], temp[102][102];
int x[5] = { 0,-1,1,0,0 };
int y[5] = { 0,0,0,1,-1 };
void move() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j].size) {
				int cnt = map[i][j].speed;
				int speed = cnt;
				int dir = map[i][j].dir;
				int siz = map[i][j].size;
				int a = i;
				int b = j;
				map[i][j] = { 0,0,0 };
				if (dir == 1 || dir == 2) {
			int rot = (R - 1) * 2;
			if (cnt >= rot)cnt %= rot;
			for (int j = 0; j < cnt; j++) {
				a += x[dir];
				b += y[dir];
				if (a < 1) {
					dir = 2;
					a += 2;
				}
				if (a > R) {
					dir = 1;
					a -= 2;
				}
			}
		}
		else {
			int rot = (C - 1) * 2;
			if (cnt >= rot)cnt %= rot;
			for (int j = 0; j < cnt; j++) {
				a += x[dir];
				b += y[dir];
				if (b < 1) {
					dir = 3;
					b += 2;
				}
				if (b > C) {
					dir = 4;
					b -= 2;
				}
			}
		}
				if (temp[a][b].size) {
					if (temp[a][b].size < siz) {
						temp[a][b].speed = speed;
						temp[a][b].dir = dir;
						temp[a][b].size = siz;
					}
				}
				else {
					temp[a][b] = { speed,dir,siz };
				}
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j] = temp[i][j];
		}
	}
	memset(temp, 0, sizeof(temp));
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		map[r][c] = { s,d,z };
	}
	int ans = 0;
	for (int j = 1; j <= C; j++) {
		for (int i = 1; i <= R; i++) {
			if (map[i][j].size) {
				ans += map[i][j].size;
				map[i][j] = { 0,0,0 };
				break;
			}
		}
		move();
	}
	cout << ans;
}