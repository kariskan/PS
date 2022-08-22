#include <iostream>
#include <vector>
using namespace std;

int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int ans = 0;

struct fish {
	int x;
	int y;
	int dir;
	bool on;
};

void fishMove(vector<fish>& f, vector<vector<int>>& map, pair<int, int> s) {

	for (int i = 1; i <= 16; i++) {
		if (!f[i].on) continue;

		for (int k = 0; k < 8; k++) {

			int nDir = f[i].dir + k;
			if (nDir > 8) nDir -= 8;
			int nx = f[i].x + dx[nDir];
			int ny = f[i].y + dy[nDir];


			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !(nx == s.first && ny == s.second)) {
				f[i].dir = nDir;

				int nowDir = f[i].dir;
				int nowX = f[i].x;
				int nowY = f[i].y;

				pair<int, int> coor = { f[i].x,f[i].y };
				f[i].x = nx, f[i].y = ny;
				f[map[nx][ny]].x = coor.first, f[map[nx][ny]].y = coor.second;

				int num = map[nx][ny];
				map[nx][ny] = i;
				map[coor.first][coor.second] = num;
				break;
			}
		}
	}
}

void go(vector<fish> f, pair<int, int> s, int sDir, vector<vector<int>> map, int cnt) { //cnt = 먹은 물고기 개수

	ans = max(ans, cnt);

	fishMove(f, map, s);

	//sharkMove start
	for (int i = 1; i <= 3; i++) {
		int nx = s.first + dx[sDir] * i;
		int ny = s.second + dy[sDir] * i;
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && map[nx][ny]) {

			int fishNum = map[nx][ny];

			map[nx][ny] = 0;
			f[fishNum].on = false;

			go(f, { nx,ny }, f[fishNum].dir, map, cnt + fishNum);

			map[nx][ny] = fishNum;
			f[fishNum].on = true;
		}
	}
	//sharkMove end
}

int main() {

	vector<fish> f(17);
	vector<vector<int>> map(4, vector<int>(4));
	pair<int, int> s = {};
	int sDir = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			fish a = { i,j,dir,true };
			f[num] = a;
			map[i][j] = num;
		}
	}

	int fNum = map[0][0];
	s = { 0,0 }, sDir = f[fNum].dir;
	f[fNum].on = false;
	map[0][0] = 0;

	go(f, s, sDir, map, fNum);

	cout << ans;
}