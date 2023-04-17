#include <iostream>
using namespace std;

long long mod = 1000000007;

long long get(long long b, long long ex) {
    if (ex == 1) {
        return b;
    }

    long long mid = get(b, ex / 2);

    if (ex % 2 == 0) {
        return (mid * mid) % mod;
    }
    return ((mid * mid) % mod * b) % mod;
}

int main() {
    int n, m;
    cin >> n >> m;

    long long np = 1;

    for (int i = 1; i <= n; i++) {
        np = (np * i) % mod;
    }

    long long bottom = 1;

    for (int i = 1; i <= m; i++) {
        bottom = (bottom * i) % mod;
    }
    for (int i = 1; i <= n - m; i++) {
        bottom = (bottom * i) % mod;
    }

    bottom = get(bottom, mod - 2) % mod;

    cout << (np * bottom) % mod;
}