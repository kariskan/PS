#include <iostream>
using namespace std;
int map[101];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			for (int j = b; j <= n; j += b) {
				map[j] = 1 - map[j];
			}
		}
		else {
			map[b] = 1 - map[b];
			int j = 1;
			for (;; j++) {
				if (b + j <= n && b - j > 0 && map[b + j] == map[b - j]) {
					map[b + j] = map[b - j] = 1 - map[b - j];
				}
				else break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << map[i] << " ";
		if (i % 20 == 0)cout << '\n';
	}
}