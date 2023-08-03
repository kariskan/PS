#include <algorithm>
#include <iostream>
using namespace std;

long long dp[91];

int main() {
    long long n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 88; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int len;
    for (int i = 1; i <= 88; i++) {
        if (dp[i] > n) {
            len = i - 1;
            break;
        }
    }
    
    while (len) {
        if (dp[len] <= n) {
            cout << 1;
            n -= dp[len];
        } else {
            cout << 0;
        }
        len--;
    }
}
