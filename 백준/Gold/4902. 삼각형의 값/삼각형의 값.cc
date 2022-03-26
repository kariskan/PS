#include <iostream>
using namespace std;
int n;
int map[1000][1000];
int sum[1000][1000];
int ans;
void run(int i, int l, int r, int s) {
	if (i < 1 || i > n || l < 1 || r > 2 * i - 1)return;
	s += sum[i][r] - sum[i][l - 1];
	ans = max(ans, s);
	if (r % 2 == 0) {
		run(i - 1, l - 2, r, s);
	}
	else {
		run(i + 1, l, r + 2, s);
	}
}
int main() {
	int cnt = 1;
	while (cin >> n, n != 0) {
		ans = -1000000000;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i * 2 - 1; j++) {
				cin >> map[i][j];
				sum[i][j] = sum[i][j - 1] + map[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i * 2 - 1; j++) {
				run(i, j, j, 0);
			}
		}
		cout << cnt++ << ". " << ans << "\n";
	}
}