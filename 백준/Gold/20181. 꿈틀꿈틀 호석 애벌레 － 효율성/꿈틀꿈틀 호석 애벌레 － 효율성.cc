#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, k, a[100001];
long long sum[100001];
long long dp[100001];

long long go(int idx) {
    if (idx > n) {
        return 0;
    }

    if (dp[idx] != -1) {
        return dp[idx];
    }

    int low = lower_bound(sum + idx, sum + 1 + n, sum[idx - 1] + k) - sum;

    return dp[idx] = max(go(idx + 1), go(low + 1) + max((long long)0, sum[low] - sum[idx - 1] - k));
}

int main() {
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }

    cout << go(1);
}