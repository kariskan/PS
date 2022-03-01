#include <iostream>
using namespace std;
int n, m;
char board[21][21];
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };
pair<int, int> c1 = { -1,-1 }, c2;

int run(int x1, int y1, int x2, int y2, int count) {
	if (count > 10) return -1;
	int fall1 = 0, fall2 = 0;
	if (!(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m)) fall1 = 1;
	if (!(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m)) fall2 = 1;
	if (fall1 && fall2) return -1;
	if (fall1 || fall2) return count;
	int ans = -1;
	for (int i = 0; i < 4; i++) {
		int nextX1, nextY1, nextX2, nextY2;
		nextX1 = x[i] + x1;
		nextY1 = y[i] + y1;
		nextX2 = x[i] + x2;
		nextY2 = y[i] + y2;
		if (nextX1 >= 0 && nextX1 < n && nextY1 >= 0 && nextY1 < m && board[nextX1][nextY1] == '#') {
			nextX1 = x1;
			nextY1 = y1;
		}
		if (nextX2 >= 0 && nextX2 < n && nextY2 >= 0 && nextY2 < m && board[nextX2][nextY2] == '#') {
			nextX2 = x2;
			nextY2 = y2;
		}
		int temp = run(nextX1, nextY1, nextX2, nextY2, count + 1);
		if (temp == -1)continue;
		if (ans == -1 || ans > temp)ans = temp;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int t = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				if (c1.first == -1) {
					c1.first = i;
					c1.second = j;
				}
				else {
					c2.first = i;
					c2.second = j;
				}
				board[i][j] = '.';
			}
		}
	cout<<run(c1.first, c1.second, c2.first, c2.second, 0);

}