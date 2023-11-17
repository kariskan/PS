#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int n, m, k;
int board[51][51];
vector<tuple<int, int, int>> v;
int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };
int ans = 1000000000;
void rotate() {
	int temp[51][51] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = board[i][j];
		}
	}
	for (auto q : v) {
		int r, c, s;
		tie(r, c, s) = q;
		for (int p = 1; p <= s; p++) {
			int i = r - p;
			int j = c - p;
			int first = temp[i][j];
			int dir = 0;
			int cnt = 0;
			while (1) {
				temp[i][j] = temp[i + x[dir]][j + y[dir]];
				i += x[dir];
				j += y[dir];
				cnt++;
				if (cnt == p * 2) {
					cnt = 0;
					dir++;
					if (dir == 4)dir = 0;
				}
				if (i + x[dir] == r - p && j + y[dir] == c - p) {
					temp[i][j] = first;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += temp[i][j];
		}
		ans = min(ans, sum);
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}
	sort(v.begin(), v.end());
	do {
		rotate();
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
}