#include <iostream>
using namespace std;

int n, s[10], b[10];
int ans = 1000000000;

void go(int idx, int sc, int bc) {
	ans = min(ans, abs(sc - bc));

	for (int i = idx; i < n; i++) {
		go(i + 1, sc * s[i], bc + b[i]);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> b[i];
	}

	for (int i = 0; i < n; i++) {
		go(i + 1, s[i], b[i]);
	}

	cout << ans;
}