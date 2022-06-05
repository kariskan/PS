#include <iostream>
using namespace std;

char map[65][65]; 
int n;
string ans;
bool check(int sti, int stj, int eni, int enj) {
	char a = map[sti][stj];
	for (int i = sti; i < eni; i++) {
		for (int j = stj; j < enj; j++) {
			if (map[i][j] != a) return false;
		}
	}
	return true;
}

void run(int sti, int stj, int eni, int enj) {
	if (check(sti, stj, eni, enj)) {
		if (sti == eni)ans.pop_back();
		if (map[sti][stj] == '1') {
			ans += "1";
		}
		else {
			ans += "0";
		}
		return;
	}
	ans += "(";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			run(sti + (eni - sti) / 2 * (i), stj + (enj - stj) / 2 * (j), sti + (eni - sti) / 2 * (i + 1), stj + (enj - stj) / 2 * (j + 1));
		}
	}
	ans += ")";
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	run(0, 0, n, n);
	cout << ans;
}