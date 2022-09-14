#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, map[52][52];

int parse(char a) {
	if (a >= 'a' && a <= 'z') return a - 'a' + 26;
	return a - 'A';
}

char parse(int a) {
	if (a < 26) return a + 'A';
	return a + 'a' - 26;
}

int main() {
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		char a, b; string c;
		cin >> a >> c >> b;
		map[parse(a)][parse(b)] = 1;
	}
	
	for (int k = 0; k < 52; k++) {
		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < 52; j++) {
				if (i == j) continue;
				if (map[i][k] && map[k][j]) {
					map[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (i == j) continue;
			if (map[i][j]) {
				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (i == j) continue;
			if (map[i][j]) {
				cout << parse(i) << " => " << parse(j) << '\n';
			}
		}
	}
}