#include <iostream>
using namespace std;

long long dp[200][70];

long long go(int k, int n) {
    if (dp[k][n]) {
        return dp[k][n];
    }
    if (k == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    long long res = 0;

    res = go(k + 1, n - 1) + go(k - 1, n - 1);

    return dp[k][n] = res;
}

int main() {
    int k, n;
    cin >> k >> n;
    cout << go(k, n);
    return 0;
}