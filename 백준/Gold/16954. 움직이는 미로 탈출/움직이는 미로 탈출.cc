#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
char board[9][9];
int x[9] = { 0,0,0,1,1,1,-1,-1,-1 };
int y[9] = { 0,1,-1,1,0,-1,1,0,-1 };

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> board[i][j];
		}
	}
	queue<tuple<int, int, int>> q;
	q.push({ 7,0,0 });
	while (!q.empty()) {
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		if ((a == 0 && b == 7) || c >= 8) {
			cout << 1;
			return 0;
		}
		q.pop();
		for (int i = 0; i < 9; i++) {
			int nx = a + x[i];
			int ny = b + y[i];
			if (nx - c >= 0 && board[nx - c][ny] == '#')continue;
			if (nx - c - 1 >= 0 && board[nx - c - 1][ny] == '#')continue;
			if (!(nx >= 0 && nx < 8 && ny >= 0 && ny < 8)) continue;
			q.push({ nx,ny,c + 1 });
		}
	}
	cout << 0;
}