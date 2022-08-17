#include <iostream>
using namespace std;

int a[100000], dp[100000][5][5], idx; //i번째 수열을 j, k 위치의 발로 눌렀을 때 최소 힘

int getStrength(int i, int j) {
	if (i == j) return 1;
	if ((i == 1 && j == 3) || (i == 2 && j == 4) || (i == 3 && j == 1) || (i == 4 && j == 2)) return 4;
	if (i == 0 || j == 0) return 2;
	return 3;
}

int go(int n, int i, int j) {

	if (idx == n) return 0;

	if (dp[n][i][j])return dp[n][i][j];

	int ret = min(go(n + 1, i, a[n]) + getStrength(j, a[n]), go(n + 1, a[n], j) + getStrength(i, a[n]));

	return dp[n][i][j] = ret;
}

int main() {

	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;
		a[idx++] = n;
	}

	cout << go(0, 0, 0);

	return 0;
}