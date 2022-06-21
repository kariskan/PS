#include <iostream>
using namespace std;
int n;
char map[7][7];
pair<int, int> t[10];
int tCount;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
bool check() {
	for (int i = 0; i < tCount; i++) {
		int tx = t[i].first;
		int ty = t[i].second;
		for (int k = 0; k < 4; k++) {
			int nx = x[k] + tx;
			int ny = y[k] + ty;
			while (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] != 'O') {
				if (map[nx][ny] == 'S')return false;
				nx = x[k] + nx;
				ny = y[k] + ny;
			}
		}
	}
	return true;
}

void run(int barrierCnt, int dx, int dy) {
	if (barrierCnt == 3) {
		if (check()) {
			cout << "YES";
			exit(0);
		}
		return;
	}

	for (int i = dx; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == dx && j <= dy)continue;
			if (map[i][j] == 'X') {
				map[i][j] = 'O';
				run(barrierCnt + 1, i, j);
				map[i][j] = 'X';
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T') {
				t[tCount++] = { i,j };
			}
		}
	}
	run(0, 0, -1);
	cout << "NO";
}