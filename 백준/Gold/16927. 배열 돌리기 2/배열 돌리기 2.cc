#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int n, m, r, a[300][300];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

// out of range
bool oor(int i, int j, int skin) {
	int x = min(i, n - i - 1);
	int y = min(j, m - j - 1);
	return min(x, y) != skin || i < 0 || i >= n || j < 0 || j >= m;
}
int getD(int i, int j, int skin) {
	if (j == skin) {
		return 1;
	}
	if (i == skin) {
		return 0;
	}
	if (j == m - skin - 1) {
		return 3;
	}
	return 2;
}
int newArr[300][300] = { 0, };

void rotate(int skin, int c) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!oor(i,j,skin)) {
				int cnt = c;
				int x = i;
				int y = j;
				int nx = x, ny = y;
				int d = getD(i, j, skin);
				while (cnt--) {
					nx += dx[d];
					ny += dy[d];
					while (oor(nx, ny, skin)) {
						nx -= dx[d];
						ny -= dy[d];
						d = (d + 1) % 4;
						nx += dx[d];
						ny += dy[d];
					}
				}
				newArr[nx][ny] = a[i][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int skin = 0; skin < min(n, m) / 2; skin++) {
		int len = (n - skin * 2) * 2 + (m - skin * 2) * 2 - 4;
		rotate(skin, r % len);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << newArr[i][j] << ' ';
		}
		cout << '\n';
	}
}