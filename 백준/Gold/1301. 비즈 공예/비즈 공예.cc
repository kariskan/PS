#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

long long dp[11][11][11][11][11][6][6];
long long go(int a, int b, int c, int d, int e, int pre, int ppre) {
	if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0) {
		return 0;
	}
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
		return 1;
	}
	if (dp[a][b][c][d][e][pre][ppre] != -1) {
		return dp[a][b][c][d][e][pre][ppre];
	}
	long long ret = 0;
	if (a > 0 && pre != 1 && ppre != 1) {
		ret += go(a - 1, b, c, d, e, 1, pre);
	}
	if (b > 0 && pre != 2 && ppre != 2) {
		ret += go(a, b - 1, c, d, e, 2, pre);
	}
	if (c > 0 && pre != 3 && ppre != 3) {
		ret += go(a, b, c - 1, d, e, 3, pre);
	}
	if (d > 0 && pre != 4 && ppre != 4) {
		ret += go(a, b, c, d - 1, e, 4, pre);
	}
	if (e > 0 && pre != 5 && ppre != 5) {
		ret += go(a, b, c, d, e - 1, 5, pre);
	}
	return dp[a][b][c][d][e][pre][ppre] = ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a[5] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(a[0], a[1], a[2], a[3], a[4], 0, 0);
}