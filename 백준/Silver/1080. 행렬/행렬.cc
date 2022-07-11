#include <iostream>
using namespace std;
char v1[50][50] = { 0, }, v2[50][50] = { 0, };
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v1[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v2[i][j];
		}
	}
	int cnt = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (v1[i][j] != v2[i][j] && i + 2 < n && j + 2 < m) {
				for (int i1 = i; i1 < i + 3; i1++) {
					for (int j1 = j; j1 < j + 3; j1++) {
						if (v1[i1][j1] == '0')v1[i1][j1] = '1';
						else v1[i1][j1] = '0';
					}
				}
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v1[i][j] != v2[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;
}