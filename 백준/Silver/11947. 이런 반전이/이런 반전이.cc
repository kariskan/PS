#include <iostream>
using namespace std;

long long get(long long n) {
    long long res = 1;
    n /= 10;
    while (n) {
        res *= 10;
        n /= 10;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long m = get(n);
        long long k = min(n, m * 5);
        cout << k * (m * 10 - 1 - k) << '\n';
    }
}