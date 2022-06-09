#include <iostream>
using namespace std;

bool check(int i, int j, int map[9][9]) {
	int c[3][10] = { 0, };
	for (int k = 0; k < 9; k++) {
		if (map[i][k] == 0)continue;
		if (c[0][map[i][k]]) {
			return false;
		}
		c[0][map[i][k]] = 1;
	}
	for (int k = 0; k < 9; k++) {
		if (map[k][j] == 0)continue;
		if (c[1][map[k][j]]) {
			return false;
		}
		c[1][map[k][j]] = 1;
	}
	for (int k = i / 3 * 3; k < i / 3 * 3 + 3; k++) {
		for (int l = j / 3 * 3; l < j / 3 * 3 + 3; l++) {
			if (map[k][l] == 0)continue;
			if (c[2][map[k][l]]) {
				return false;
			}
			c[2][map[k][l]] = 1;
		}
	}
	return true;
}
void run(int map[9][9]) {
	int cnt = 0;
	for (int i1 = 0; i1 < 9; i1++) {
		for (int j1 = 0; j1 < 9; j1++) {
			if (map[i1][j1] != 0)continue;
			cnt++;
			for (int k = 1; k <= 9; k++) {
				map[i1][j1] = k;
				if (check(i1, j1, map)) {
					run(map);
				}
				map[i1][j1] = 0;
			}
			return;
		}
	}
	if (cnt == 0) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
}

int main() {
	int map[9][9] = { 0, };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	run(map);
}