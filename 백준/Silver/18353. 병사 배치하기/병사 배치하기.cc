#include <iostream>
using namespace std;

int a[2000], dp[2000];

int main() {

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int m = 0;

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		m = max(m, dp[i]);
	}

	cout << n - m;

}