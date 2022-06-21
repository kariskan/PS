#include <iostream>
using namespace std;
int n, m;
string inp;
char map[101][101];
int madMap[101][101];
int x[9] = { 1,1,1,0,0,0,-1,-1,-1 };
int y[9] = { -1,0,1,-1,0,1,-1,0,1 };
pair<int, int> mad[10000];
pair<int, int> ar;
int madCnt;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				ar = { i,j };
			}
			if (map[i][j] == 'R') {
				mad[madCnt++] = { i,j };
				madMap[i][j]++;
			}
		}
	}
	cin >> inp;
	for (int i = 0; i < inp.length(); i++) {
		map[ar.first][ar.second] = '.';
		ar.first += x[inp[i] - '0' - 1];
		ar.second += y[inp[i] - '0' - 1];
		if (map[ar.first][ar.second] == 'R') {
			cout << "kraj " << i + 1;
			return 0;
		}
		map[ar.first][ar.second] = 'I';
		for (int i1 = 0; i1 < madCnt; i1++) {
			int madX = mad[i1].first;
			int madY = mad[i1].second;
			if (madX == -1 && madY == -1)continue;
			int minDis = 10000;
			int minIdx = -1;
			for (int k = 0; k < 9; k++) {
				int madNx = madX + x[k];
				int madNy = madY + y[k];
				if (minDis > abs(madNx - ar.first) + abs(madNy - ar.second)) {
					minDis = abs(madNx - ar.first) + abs(madNy - ar.second);
					minIdx = k;
				}
			}
			madMap[madX][madY]--;
			map[madX][madY] = '.';
			madX += x[minIdx];
			madY += y[minIdx];
			if (map[madX][madY] == 'I') {
				cout << "kraj " << i + 1;
				return 0;
			}
			map[madX][madY] = 'R';
			madMap[madX][madY]++;
			mad[i1] = { madX,madY };
		}

		for (int j = 0; j < madCnt; j++) {
			map[mad[j].first][mad[j].second] = 'R';
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (madMap[j][k] > 1) {
					for (int l = 0; l < madCnt; l++) {
						if (mad[l].first == j && mad[l].second == k) {
							mad[l] = { -1,-1 };
						}
					}
					madMap[j][k] = 0;
					map[j][k] = '.';
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}