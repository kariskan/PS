#include <iostream>
using namespace std;

int n, a[30], k[30][40001], m;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	k[0][a[0]] = 1;
	for (int i = 1; i < n; i++) {
		k[i][a[i]] = 1;
		for (int j = 0; j < 40001; j++) {
			if (k[i - 1][j]) {
				k[i][abs(j - a[i])] = 1;
				k[i][j + a[i]] = 1;
				k[i][j] = 1;
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		if (k[n - 1][num])cout << "Y ";
		else cout << "N ";
	}
}