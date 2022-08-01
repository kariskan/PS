#include <iostream>
#include <cmath>
using namespace std;

int n;
int dp[101][1024][10]; //길이가 i이면서 j집합을 포함하고, k로 끝나는 수
int main() {
	cin >> n;
	for (int j = 2; j < 1024; j *= 2) {
		dp[1][j][(int)log2(j)] = 1;
	}
	int ans = 0;
	int mod = 1000000000;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < (1 << 10); j++) {
			for (int k = 0; k < 10; k++) {
				if (k == 0) {
					dp[i][j | (1 << k)][k] = (dp[i][j | (1 << k)][k] % mod + dp[i - 1][j][k + 1] % mod) % mod;
				}
				else if (k == 9) {
					dp[i][j | (1 << k)][k] = (dp[i][j | (1 << k)][k] % mod + dp[i - 1][j][k - 1] % mod) % mod;
				}
				else {
					dp[i][j | (1 << k)][k] = (dp[i][j | (1 << k)][k] % mod + dp[i - 1][j][k - 1] % mod + dp[i - 1][j][k + 1] % mod) % mod;
				}
				if (i == n && j == 1023) {
					ans = (ans % mod + dp[i][j][k] % mod) % mod;
				}
			}
		}
	}
	cout << ans;
}