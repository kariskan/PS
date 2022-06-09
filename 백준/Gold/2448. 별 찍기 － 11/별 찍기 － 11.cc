#include <iostream>
using namespace std;
char ans[10000][10000];
void print(int i, int j) {
	ans[i][j + 2] = '*';
	ans[i + 1][j + 1] = ans[i + 1][j + 3] = '*';
	for (int k = j; k < j + 5; k++)ans[i + 2][k] = '*';
}
void run(int n, int i, int j) {
	if (n == 3) {
		print(i, j);
		return;
	}
	else {
		run(n / 2, i, j + n / 2);
		run(n / 2, i + n / 2, j);
		run(n / 2, i + n / 2, j + n);
	}
}

int main() {
	int n;
	cin >> n;
	run(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (ans[i][j] != '*')cout << " ";
			else cout << ans[i][j];
		}
		cout << "\n";
	}
}