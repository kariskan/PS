#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int a[15][15] = { 0, };
	for (int i = 0; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			if (i == 0)a[i][j] = j;
			else {
				for (int k = 1; k <= j; k++)a[i][j] += a[i - 1][k];
			}
		}
	}
	while (t--) {
		int k, n;
		cin >> k >> n;
		cout << a[k][n] << "\n";
	}
}