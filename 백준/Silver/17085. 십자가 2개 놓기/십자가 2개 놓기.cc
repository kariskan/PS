#include <iostream>
using namespace std;

int n, m;
char board[16][16];
int visit[16][16];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '#') {
				int cnt = 0;
				while (board[i + cnt][j] == '#' && board[i - cnt][j] == '#' && board[i][j + cnt] == '#' && board[i][j - cnt] == '#') {
					visit[i + cnt][j] = visit[i - cnt][j] = visit[i][j + cnt] = visit[i][j - cnt] = 1;
					cnt++;
					for (int i1 = 0; i1 < n; i1++) {
						for (int j1 = 0; j1 < m; j1++) {
							if (board[i1][j1] == '#' && !visit[i1][j1]) {
								int cnt2 = 0;
								while (board[i1 + cnt2][j1] == '#' && board[i1 - cnt2][j1] == '#' && board[i1][j1 + cnt2] == '#' && board[i1][j1 - cnt2] == '#' &&
									!visit[i1 + cnt2][j1] && !visit[i1 - cnt2][j1] && !visit[i1][j1 + cnt2] && !visit[i1][j1 - cnt2]) {
									visit[i1 + cnt2][j1] = visit[i1 - cnt2][j1] = visit[i1][j1 + cnt2] = visit[i1][j1 - cnt2] = 1;
									ans = max(ans, ((cnt - 1) * 4 + 1) * ((cnt2) * 4 + 1));
									cnt2++;
								}
								while (cnt2--) {
									visit[i1 + cnt2][j1] = visit[i1 - cnt2][j1] = visit[i1][j1 + cnt2] = visit[i1][j1 - cnt2] = 0;
								}
							}
						}
					}
				}
				while (cnt--) {
					visit[i + cnt][j] = visit[i - cnt][j] = visit[i][j + cnt] = visit[i][j - cnt] = 0;
				}
			}
		}
	}
	cout << ans;
}