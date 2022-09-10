#include <iostream>
#include <cstring>
using namespace std;

int n, d, a[501][501], b[501][501];

void cw() {
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++) {
		b[i][(n + 1) / 2] = a[i][i];
		b[i][n - i + 1] = a[i][(n + 1) / 2];
		b[(n + 1) / 2][i] = a[n - i + 1][i];
		b[i][i] = a[(n + 1) / 2][i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!b[i][j]) continue;
			a[i][j] = b[i][j];
		}
	}
}

void ccw() {
	memset(b, 0, sizeof(b));

	for (int i = 1; i <= n; i++) {

		b[i][(n + 1) / 2] = a[i][n - i + 1];
		b[i][i] = a[i][(n + 1) / 2];
		b[(n + 1) / 2][i] = a[i][i];
		b[i][n - i + 1] = a[(n + 1) / 2][n - i + 1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!b[i][j]) continue;
			a[i][j] = b[i][j];
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> d;
		memset(a, 0, sizeof(a));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < abs(d) / 45; i++) {
			if (d < 0)ccw();
			else cw();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}