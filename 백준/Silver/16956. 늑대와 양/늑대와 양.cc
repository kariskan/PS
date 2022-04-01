#include <iostream>
using namespace std;
char a[500][501];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '.')a[i][j] = 'D';
		}
	}
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'W') {
				for (int k = 0; k < 4; k++) {
					int nx = i + x[k];
					int ny = j + y[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 'S') {
						cout << 0;
						return 0;
					}
				}
			}
		}
	}
	cout << 1 << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}