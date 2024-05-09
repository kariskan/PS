#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

long long a[5000], dp[5000], n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = LLONG_MAX;
	}
	dp[0] = 0;
	for (long long i = 1; i < n; i++) {
		for (long long j = 0; j < i; j++) {
			long long power = (i - j) * (1 + abs(a[i] - a[j]));
			dp[i] = min(dp[i], max(dp[j], power));
		}
	}
    cout << dp[n - 1];
}