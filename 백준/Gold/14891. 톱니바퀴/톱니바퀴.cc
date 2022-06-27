#include <iostream>
using namespace std;

string s[4]; // i==2 오른쪽, i==6 왼쪽
int k;
//1이면 cw, 0이면 ccw
void rotate(int n, int r) {
	if (r == 1) {
		char c = s[n][7];
		for (int i = 7; i > 0; i--) {
			s[n][i] = s[n][i - 1];
		}
		s[n][0] = c;
	}
	else {
		char c = s[n][0];
		for (int i = 0; i < 7; i++) {
			s[n][i] = s[n][i + 1];
		}
		s[n][7] = c;
	}
}
void cw(int n, int r, int dir) { //dir이 0이면 왼쪽에서 옴
								 //dir이 1이면 오른쪽에서 옴
	if (r == 1) {
		if (dir != 1 && n != 3 && s[n][2] != s[n + 1][6]) { //오른쪽
			cw(n + 1, 0, 0);
		}
		if (dir != 0 && n != 0 && s[n][6] != s[n - 1][2]) { //왼쪽
			cw(n - 1, 0, 1);
		}
	}
	else {
		if (dir != 1 && n != 3 && s[n][2] != s[n + 1][6]) { //오른쪽
			cw(n + 1, 1, 0);
		}
		if (dir != 0 && n != 0 && s[n][6] != s[n - 1][2]) { //왼쪽
			cw(n - 1, 1, 1);
		}
	}
	rotate(n, r);
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		cw(a - 1, b, -1);
	}
	int sum = s[0][0] == '1' ? 1 : 0;
	sum += s[1][0] == '1' ? 2 : 0;
	sum += s[2][0] == '1' ? 4 : 0;
	sum += s[3][0] == '1' ? 8 : 0;
	cout << sum;
}