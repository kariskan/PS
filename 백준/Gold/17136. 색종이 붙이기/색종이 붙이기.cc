#include <iostream>
using namespace std;

int map[10][10], p[6] = { 0,5,5,5,5,5 };
int ans = -1;

void go(int x, int y, int cnt) {
	if (ans != -1 && ans < cnt) return;

	if (x == 10) {
		if (ans == -1 || ans > cnt) {
			ans = cnt;
		}
		return;
	}
	
	if (y == 10) {
		go(x + 1, 0, cnt);
		return;
	}

	if (map[x][y] == 0) {
		go(x, y + 1, cnt);
		return;
	}

	for (int s = 1; s <= 5; s++) {
		if (x + s > 10 || y + s > 10 || p[s] == 0)continue;

		bool ok = true;
		for (int i = x; i < x + s; i++) {
			for (int j = y; j < y + s; j++) {
				if (map[i][j] != 1) {
					ok = false;
					break;
				}
			}
			if (!ok)break;
		}
		if (!ok)continue;

		for (int i = x; i < x + s; i++) {
			for (int j = y; j < y + s; j++) {
				map[i][j] = 0;
			}
		}
		p[s]--;
		go(x, y + s, cnt + 1);
		p[s]++;
		for (int i = x; i < x + s; i++) {
			for (int j = y; j < y + s; j++) {
				map[i][j] = 1;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
	
	go(0, 0, 0);

	cout << ans;
}