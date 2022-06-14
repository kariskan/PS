#include <iostream>
#include <map>
#include <set>
using namespace std;

int n, m;
int visit[1001][1001];
char board[1001][1001];
int x[4] = { -1,1,0,0 };
int y[4] = { 0,0,-1,1 };
int cnt = 1;
map<char, int> ma = { {'U',0},{'D',1},{'L',2},{'R',3} };

int run(int i, int j) {
	visit[i][j] = cnt;
	int dir = ma[board[i][j]];
	int nx = i + x[dir];
	int ny = j + y[dir];

	if (visit[nx][ny]) {
		return visit[i][j] = visit[nx][ny];
	}
	else {
		return visit[i][j] = run(nx, ny);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				cnt++;
				visit[i][j] = run(i, j);
			}
			if (s.find(visit[i][j]) == s.end()) {
				s.insert(visit[i][j]);
			}
		}
	}
	cout << s.size();
}