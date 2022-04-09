#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int lo[100][100], k[100][100], temp[100][100];
int n, m;
void rotate() {
	int tArr[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tArr[i][j] = k[n - j - 1][i];
		}
	}
	memmove(k, tArr, sizeof(k));
}

void copy(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i + x][j + y] = k[i][j];
		}
	}
}

bool check() {
	
	for (int i = 0; i < m + n - 1; i++) {
		for (int j = 0; j < m + n - 1; j++) {
			memset(temp, 0, sizeof(temp));
			copy(i, j);
			int brk = 0;
			for (int i1 = n - 1; i1 < n + m - 1; i1++) {
				for (int j1 = n - 1; j1 < n + m - 1; j1++) {
					if (temp[i1][j1] == lo[i1][j1]) {
						brk = 1;
						break;
					}
				}
				if (brk)break;
			}
			if (!brk) {
				return true;
			}
		}
	}
	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	n = key.size();
	m = lock.size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			lo[i + n - 1][j + n - 1] = lock[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			k[i][j] = key[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (check()) {
			return true;
		}
		rotate();
	}
	return false;
}