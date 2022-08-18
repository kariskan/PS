#include <iostream>
#include <cstring>
using namespace std;

int n, a[2000], b[2000];
int dp[2000][2000]; //i번째, j번재 카드가 제일 위에있을 경우 얻을 수 있는 최대 점수

int go(int i, int j) {
	
	if (i == n || j == n)return 0;

	if (dp[i][j] != -1)return dp[i][j];

	int ret = 0;

	ret = max(go(i + 1, j), go(i + 1, j + 1));

	if (a[i] > b[j]) {
		ret = max(ret, go(i, j + 1) + b[j]);
	}

	return dp[i][j] = ret;
}

int main() {
	
	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	cout << go(0, 0);
}