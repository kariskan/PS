#include <iostream>
using namespace std;

long long a, b;

long long go(long long n) {
    if (n == 0) {
        return 0;
    }

    long long sum = 0;
    long long p = 1;
    while (p * 2 <= n) {
        p *= 2;
    }
    long long res = 0;
    while (p != 0) {
        long long t = n / p - sum;
        res += p * (n / p - sum);
        sum += t;
        p /= 2;
    }

    return res;
}

int main() {
    cin >> a >> b;

    cout << go(b) - go(a - 1);
}