#include <cmath>
#include <iostream>
using namespace std;

long long n, dp[1000001];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = (dp[i - 1] + dp[i / 2]) % 1000000000;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    
    cout << dp[n];
}