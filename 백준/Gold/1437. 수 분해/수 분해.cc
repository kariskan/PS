#include <iostream>
using namespace std;

int dp[1000001];

int go(int n) {
    if (dp[n]) {
        return dp[n];
    }
    if (n <= 4) {
        return n;
    }
    
    return dp[n] = (go(n - 3) * 3) % 10007;
}

int main() {
    int n;
    cin >> n;
    cout << go(n);
}