#include <iostream>
#include <cstring>
using namespace std;

int m, n;
int map[2000];
int main() {
	cin >> m >> n;
	int zero, one, two;
	memset(map, 0, sizeof(map));
	for (int i = 0; i < n; i++) {
		cin >> zero >> one >> two;
		for (int j = zero; j < zero + one; j++) {
			map[j] += 1;
		}
		for (int j = zero + one; j < zero + one + two; j++) {
			map[j] += 2;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1) {
				cout << map[m - i] + 1 << " ";
			}
			else {
				cout << map[m + j - 2] + 1 << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}