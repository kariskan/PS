#include <iostream>
using namespace std;

long long a[31][31];

int main() {
	a[0][0] = a[1][0] = a[1][1] = 1;

	for (int i = 2; i <= 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) a[i][j] = 1;
			else {
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			}
		}
	}

	int r, c, w; cin >> r >> c >> w;
	r--;
	c--;
	long long cnt = 0, ans = 0;
	for (int i = r; i < r + w; i++) {
		cnt++;
		for (int j = c; j < c + cnt; j++) {
			ans += a[i][j];
		}
	}

	cout << ans;
}