#include <string>
#include <vector>
#include <cstring>
#include <deque>
#include <tuple>
using namespace std;
int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };
int money[4][25][25];
int n;
int solution(vector<vector<int>> board) {
	n = board.size();
	deque<tuple<int, int, int>>d;
	d.push_front({ 0,0,0 });
	while (!d.empty()) {
		int a, b, c;
		tie(a, b, c) = d.front();
		d.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = b + x[i];
			int ny = c + y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] != 1) {
				if (money[i][nx][ny] == 0) {
					if (a == i || (b == 0 && c == 0)) {
						money[i][nx][ny] = money[a][b][c] + 100;
						d.push_front({ i,nx,ny });
					}
					else {
						money[i][nx][ny] = money[a][b][c] + 600;
						d.push_back({ i,nx,ny });
					}
				}
				else {
					if (a == i || (b == 0 && c == 0)) {
						if (money[i][nx][ny] > money[a][b][c] + 100) {
							money[i][nx][ny] = money[a][b][c] + 100;
							d.push_front({ i,nx,ny });
						}
					}
					else {
						if (money[i][nx][ny] > money[a][b][c] + 600) {
							money[i][nx][ny] = money[a][b][c] + 600;
							d.push_back({ i,nx,ny });
						}
					}
				}
			}
		}
	}
	int answer = -1;
	for (int i = 0; i < 4; i++) {
		if (money[i][n - 1][n - 1] == 0)continue;
		if (answer == -1 || money[i][n - 1][n - 1] < answer) {
			answer = money[i][n - 1][n - 1];
		}
	}
	return answer;
}