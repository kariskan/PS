#include <iostream>
using namespace std;

//가로는 (n - 1) * 4 + 1, 세로는 (n - 1) * 8 + 1

char map[1000][1000];
int n;

void go(int left, int right, int top, int bottom) {
	if (left > right || top > bottom)return;
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			if (i == top || i == bottom || j == left || j == right) {
				map[i][j] = '*';
			}
		}
	}
	go(left + 2, right - 2, top + 2, bottom - 2);
}

int main() {
	cin >> n;
	go(1, (n - 1) * 4 + 1, 1, (n - 1) * 4 + 1);

	for (int i = 1; i <= (n - 1) * 4 + 1; i++) {
		for (int j = 1; j <= (n - 1) * 4 + 1; j++) {
			if (map[i][j] == '*') cout << map[i][j];
			else cout << ' ';
		}
		cout << '\n';
	}
}