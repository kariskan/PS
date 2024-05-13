#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

int a[5001];
bool dp[5001];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dp[1] = true;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (dp[j] == false) {
				continue;
			}
			int nxt = (i - j) * (1 + abs(a[i] - a[j]));
			if (nxt <= k) {
				dp[i] = true;
			}
		}
	}

	if (dp[n]) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}