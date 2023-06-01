#include <iostream>
using namespace std;

long long n;

int main() {
    cin >> n;
    if (n == 0) {
        cout << "NO";
        return 0;
    }
    long long p = 1;
    while (p * 3 <= n) {
        p *= 3;
    }

    while (p != 0) {
        while (p > n) {
            p /= 3;
        }
        n -= p;
        p /= 3;
    }

    if (n == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}