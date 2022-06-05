#include <iostream>
using namespace std;
int map[2187][2187];
int ans1, ans2, ans3;
bool check(int sti, int stj, int eni, int enj) {
	int a = map[sti][stj];
	for (int i = sti; i < eni; i++) {
		for (int j = stj; j < enj; j++) {
			if (map[i][j] != a) return false;
		}
	}
	return true;
}
void run(int sti, int stj, int eni, int enj) {
	if (sti == eni || check(sti, stj, eni, enj)) {
		if (map[sti][stj] == 1) {
			ans3++;
		}
		else if (map[sti][stj] == 0) {
			ans2++;
		}
		else {
			ans1++;
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			run(sti + (eni - sti) / 3 * (i), stj + (enj - stj) / 3 * (j), sti + (eni - sti) / 3 * (i + 1), stj + (enj - stj) / 3 * (j + 1));
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	run(0, 0, n, n);
	cout << ans1 << "\n" << ans2 << "\n" << ans3;
}