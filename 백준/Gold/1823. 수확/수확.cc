#include <iostream>
using namespace std;

long long a[2000], n, dp[2000][2000];

long long go(int left, int right, int cnt) {
    if (left > right) {
        return 0;
    }
    if (dp[left][right]) {
        return dp[left][right];
    }
    if (left == right) {
        return dp[left][right] = a[left] * cnt;
    }

    return dp[left][right] = max(go(left + 1, right, cnt + 1) + a[left] * cnt, go(left, right - 1, cnt + 1) + a[right] * cnt);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << go(0, n - 1, 1);
}