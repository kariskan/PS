#include <iostream>
#include <vector>
using namespace std;
int board[9][9];
int c[10][10], c2[10][10], c3[10][10]; //i행에 숫자 j가 있으면 1, i열에 숫자 j가 있으면 1, i번 작은 정사각형에 숫자 j가 있으면 1

int square(int i, int j) {
	return (i / 3) * 3 + j / 3;
}

void run(int z) {
	if (z == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (j == 8)cout << board[i][j] << "\n";
				else cout << board[i][j] << " ";
			}
		}
		exit(0);
	}
	int x = z / 9, y = z % 9;
	if (board[x][y])run(z + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
				c[x][i] = 1;
				c2[y][i] = 1;
				c3[square(x, y)][i] = 1;
				board[x][y] = i;
				run(z + 1);
				c[x][i] = 0;
				c2[y][i] = 0;
				c3[square(x, y)][i] = 0;
				board[x][y] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				c[i][board[i][j]] = 1;
				c2[j][board[i][j]] = 1;
				c3[square(i, j)][board[i][j]] = 1;
			}
		}
	}
	run(0);
}