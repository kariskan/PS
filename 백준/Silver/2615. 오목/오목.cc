#include <iostream>
using namespace std;

int a[19][19];
int x[8] = { -1,1,0,0,1,-1,1,-1 };
int y[8] = { 1,-1,1,-1,1,-1,0,0 };

bool ok(int x, int y) {
	return x >= 0 && x < 19 && y >= 0 && y < 19;
}

int main() {
	
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (a[i][j] == 0) continue;

			for (int k = 0; k < 8; k += 2) {
				int cnt = 1;

				int mini = i, minj = j;

				int nx = i + x[k];
				int ny = j + y[k];
				while (ok(nx, ny) && a[i][j] == a[nx][ny]) {
					if (minj >= ny) {
						if (minj > ny) {
							minj = ny;
							mini = nx;
						}
						else {
							mini = min(mini, nx);
						}
					}
					cnt++;
					nx += x[k];
					ny += y[k];
				}
				nx = i + x[k + 1];
				ny = j + y[k + 1];
				while (ok(nx, ny) && a[i][j] == a[nx][ny]) {
					if (minj >= ny) {
						if (minj > ny) {
							minj = ny;
							mini = nx;
						}
						else {
							mini = min(mini, nx);
						}
					}
					cnt++;
					nx += x[k + 1];
					ny += y[k + 1];
				}
				if (cnt == 5) {
					cout << a[i][j] << '\n' << mini + 1 << ' ' << minj + 1;
					return 0;
				}
			}
		}
	}

	cout << 0;
}