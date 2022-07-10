#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int cnt;
int r, c;
int answer = -1;
vector<pair<int, int>> info[7];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int get(int x1, int y1, int x2, int y2, vector<vector<int>> board) {
	queue<pair<int, int>> q;
	int visit[4][4] = { 0, };
	q.push({ x1, y1 });
	visit[x1][y1] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a == x2 && b == y2) {
			return visit[a][b];
		}
		for (int k = 0; k < 8; k++) {
			if (k < 4) {
				int nx = a + x[k];
				int ny = b + y[k];
				if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !visit[nx][ny]) {
					q.push({ nx,ny });
					visit[nx][ny] = visit[a][b] + 1;
				}
			}
			else {
				int dir = k - 4;
				int nx = a;
				int ny = b;
				while (nx + x[dir] >= 0 && nx+x[dir] < 4 && ny+y[dir] >= 0 && ny+y[dir] < 4) {
					nx += x[dir];
					ny += y[dir];
					if (board[nx][ny] != 0)break;
				}
				if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !visit[nx][ny]) {
					q.push({ nx,ny });
					visit[nx][ny] = visit[a][b] + 1;
				}
			}
		}
	}
}
void go(int curx, int cury, vector<int> seq, int idx, int sum, int t, int s, vector<vector<int>> board) { //t는 개수,s는 순서
	if (idx >= seq.size()) {
		if (answer == -1 || answer > sum) {
			answer = sum;
		}
		return;
	}
	pair<int, int> p1 = info[seq[idx]][0];
	pair<int, int> p2 = info[seq[idx]][1];
	if (t == 0) {
		int se = get(curx, cury, p1.first, p1.second, board);
		board[p1.first][p1.second] = 0;
		go(p1.first, p1.second, seq, idx, sum + se, 1, 1, board);
		board[p1.first][p1.second] = 1;
		se = get(curx, cury, p2.first, p2.second, board);
		board[p2.first][p2.second] = 0;
		go(p2.first, p2.second, seq, idx, sum + se, 1, 0, board);
		board[p2.first][p2.second] = 1;
	}
	else {
		int se = get(curx, cury, info[seq[idx]][s].first, info[seq[idx]][s].second, board);
		board[info[seq[idx]][s].first][info[seq[idx]][s].second] = 0;
		go(info[seq[idx]][s].first, info[seq[idx]][s].second, seq, idx + 1, sum + se, 0, 0, board);
		board[info[seq[idx]][s].first][info[seq[idx]][s].second] = 1;
	}
}
int solution(vector<vector<int>> board, int r, int c) {
	::r = r;
	::c = c;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cnt = max(cnt, board[i][j]);
			if (board[i][j] != 0) {
				info[board[i][j]].push_back({ i,j });
			}
		}
	}
	vector<int> seq(cnt);
	for (int i = 0; i < cnt; i++)seq[i] = i + 1;
	do {
		go(r, c, seq, 0, 0, 0, 0, board);
	} while (next_permutation(seq.begin(), seq.end()));
	return answer;
}
