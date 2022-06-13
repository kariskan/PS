#include <iostream>
#include <deque>
using namespace std;

typedef struct chess {
	int x;
	int y;
	int dir; //1오 2왼 3위 4아래
};

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int n, k;
int map[13][13];
deque<int> de[13][13];
chess en[11];
int ans;

void toWhite(int x, int y, int dir, int nx, int ny) {
	while (!de[x][y].empty()) { //모든 말 이동
		int nChess = de[x][y].back(); //이동하려는 말
		de[x][y].pop_back(); //아래부터 빼서
		en[nChess] = { nx,ny,en[nChess].dir };
		de[nx][ny].push_front(nChess); //위로 이동
	}
}

void toRed(int x, int y, int dir, int nx, int ny) {
	while (!de[x][y].empty()) { //모든 말 이동
		int nChess = de[x][y].front(); //이동하려는 말
		de[x][y].pop_front(); //위에서부터 빼서(순서 반전)
		en[nChess] = { nx,ny,en[nChess].dir };
		de[nx][ny].push_front(nChess); //위로 이동
	}
}

void toBlue() {

}

int changeDir(int dir) {
	if (dir == 1)return 2;
	if (dir == 2)return 1;
	if (dir == 3)return 4;
	if (dir == 4)return 3;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		en[i] = { a,b,c };
		de[a][b].push_back(i);
	}
	while (ans <= 1000) {

		ans++;

		for (int i = 1; i <= k; i++) {
			int x = en[i].x;
			int y = en[i].y;
			int dir = en[i].dir;
			
			if (de[x][y].back() != i)continue; //이동하려는 말이 맨 밑이 아니면 이동 x

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if (map[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= n) { //흰
				toWhite(x, y, dir, nx, ny);
			}
			else if (map[nx][ny] == 1 && nx > 0 && nx <= n && ny > 0 && ny <= n) { //빨강
				toRed(x, y, dir, nx, ny);
			}
			else { //파랑
				int cDir = changeDir(dir);
				nx = x + dx[cDir];
				ny = y + dy[cDir];
				en[i].dir = cDir;
				if (map[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= n) {
					toWhite(x, y, cDir, nx, ny);
				}
				else if (map[nx][ny] == 1 && nx > 0 && nx <= n && ny > 0 && ny <= n) {
					toRed(x, y, cDir, nx, ny);
				}
				else {
					continue;
				}
			}
			if (de[nx][ny].size() >= 4) {
				cout << ans;
				return 0;
			}
		}
	}
	if (ans > 1000)ans = -1;
	cout << ans;
}