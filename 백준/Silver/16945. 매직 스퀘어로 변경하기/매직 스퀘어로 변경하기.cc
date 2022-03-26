#include <iostream>
#include <algorithm>
using namespace std;
int c[9];
int map[3][3];
bool check() {
	int sum = c[0] + c[4] + c[8];
	if (sum != c[2] + c[4] + c[6])return false;
	for (int i = 0; i < 3; i++) {
		if (sum != c[i * 3] + c[i * 3 + 1] + c[i * 3 + 2] ||
			sum != c[i] + c[3 + i] + c[6 + i])return false;
	}
	return true;
}
int sum() {
	int res = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res += abs(map[i][j] - c[i * 3 + j]);
		}
	}
	return res;
}
int ans = 1000000000;
int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
			c[i * 3 + j] = i * 3 + j + 1;
		}
	}
	do {
		if (check())ans = min(ans, sum());
	} while (next_permutation(c, c + 9));
	cout << ans;
}