#include <iostream>
using namespace std;

int map[1001][1001];
int minElement = -1, mini = -1, minj = -1;
string ans = "";
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	if (n % 2 != 0 || m % 2 != 0) {
		if (n % 2 != 0) { //세로가 홀수
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m - 1; j++) {
					if (i % 2 == 0) {
						cout << 'R';
					}
					else cout << 'L';
				}
				if (i < n - 1) cout << 'D';
			}
		}
		else if (m % 2 != 0) { //가로가 홀수
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n - 1; j++) {
					if (i % 2 == 0) {
						cout << 'D';
					}
					else cout << 'U';
				}
				if (i < m - 1) cout << 'R';
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if ((i + j) % 2 != 0) {
					if (minElement == -1 || minElement > map[i][j]) {
						minElement = map[i][j];
						mini = i; minj = j;
					}
				}
			}
		}
		for (int i = 0; i < (mini % 2 == 0 ? mini - 2 : mini - 1); i++) {
			for (int j = 0; j < m - 1; j++) {
				if (i % 2 == 0)ans += "R";
				else ans += "L";
			}
			ans += "D";
		}
		for (int i = 0; i < minj - 1; i++) {
			if (i % 2 == 0)ans += "DR";
			else ans += "UR";
		}
		for (int i = minj; i < m; i++) {
			if (i % 2 == 0)ans += "RU";
			else ans += "RD";
		}
		if (mini % 2 != 0) {
			n -= mini + 1;
		}
		else {
			n -= mini;
		}
		for (int i = 1; i <= n; i++) {
			ans += "D";
			for (int j = 1; j < m; j++) {
				if (i % 2 != 0)ans += "L";
				else ans += "R";
			}
		}
		cout << ans;
	}
}