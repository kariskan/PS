#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	char board[102][101];
	int visit[101][101] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	vector<tuple<int, int, int>> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '*') {
				int cnt = 1;
				while (1) {
					if (board[i + cnt][j] == '*' && board[i - cnt][j] == '*' && board[i][j + cnt] == '*' && board[i][j - cnt] == '*') {
						visit[i][j] = visit[i + cnt][j] = visit[i - cnt][j] = visit[i][j - cnt] = visit[i][j + cnt] = 1;
						v.push_back({ i,j,cnt });
						cnt++;
					}
					else {
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '*' && !visit[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << v.size() << "\n";
	for (auto a : v) {
		int x, y, s;
		tie(x, y, s) = a;
		cout << x << " " << y << " " << s << "\n";
	}
}