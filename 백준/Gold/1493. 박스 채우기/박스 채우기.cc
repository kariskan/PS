#include <iostream>
#include <climits>
using namespace std;

int min(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	if (b <= a && b <= c) return b;
	return c;
}

int n, a[21];

int go(int w, int m, int h) {
	
	if (w == 0 || m == 0 || h == 0)return 0;

	int idx = -1;

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] && (1 << i) <= min(w, m, h)) {
			idx = i;
			break;
		}
	}

	if (idx == -1) {
		cout << -1;
		exit(0);
	}

	int c = 1 << idx;
	a[idx]--;
	int ret = go(w - c, m, h) + go(c, m, h - c) + go(c, m - c, c) + 1;
	return ret;
}

int main() {
	int l, m, h;
	cin >> l >> m >> h >> n;

	for (int i = 0; i < n; i++) {
		int c, b; cin >> c >> b;
		a[c] = b;
	}

	cout << go(l, m, h);
}