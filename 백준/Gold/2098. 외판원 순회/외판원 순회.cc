#include <iostream>
using namespace std;
int n;
int map[16][16];
int dp[16][1<<16];
int inf = 987654321;
int go(int node, int bit) {
	if(dp[node][bit]) return dp[node][bit];
	if (bit == (1 << n) - 1) {
		if (map[node][0] == 0) {
			return inf;
		}
		return map[node][0];
	}
	int res = inf;
	for (int i = 0; i < n; i++) {
		if (!(bit & (1 << i)) && map[node][i]) {
			res = min(res, go(i, bit | (1 << i)) + map[node][i]);
		}
	}
	return dp[node][bit] = res;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cout << go(0, 1);
}