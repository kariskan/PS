#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct shark {
	int i;
	int j;
	int speed;
	int dir;
	int size;
	bool deleted;
};

bool compare(shark& a, shark& b) {
	return a.i < b.i;
}

int R, C, M;
vector<shark> v;
int x[5] = { 0,-1,1,0,0 };
int y[5] = { 0,0,0,1,-1 };
int map[101][101], temp[101][101];

void move() {
	for (int i = 0; i < v.size(); i++) {
		shark t = v[i];
		if (t.deleted)continue;
		int dir = t.dir;
		int siz = t.size;
		int a = t.i;
		int b = t.j;
		int cnt = t.speed;
		int speed = cnt;

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

		if (temp[a][b]) {
			if (v[temp[a][b] - 1].size < siz) {
				v[temp[a][b] - 1].deleted = true;
				temp[a][b] = i + 1;
				v[i] = { a,b,speed,dir,siz,false };
			}
			else {
				v[i].deleted = true;
			}
		}
		else {
			temp[a][b] = i + 1;
			v[i] = { a,b,speed,dir,siz,false };
		}
	}
	memset(map, 0, sizeof(map));
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
		v.push_back({ r,c,s,d,z,false });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		map[v[i].i][v[i].j] = i + 1;
	}
	int ans = 0;
	for (int i = 1; i <= C; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j].j == i && !v[j].deleted) {
				ans += v[j].size;
				v[j].deleted = true;
				map[v[j].i][v[j].j] = 0;
				break;
			}
		}
		move();
		sort(v.begin(), v.end(), compare);
	}
	cout << ans;
}