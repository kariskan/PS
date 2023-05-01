#include <cmath>
#include <iostream>
using namespace std;

long long p[40], m[40];

int main() {
    long long n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    p[0] = 1;
    for (int i = 1; i < 40; i++) {
        if (i % 2 == 0) {
            p[i] = p[i - 1] + (long long)pow(2, i);
            m[i] = m[i - 1];
        } else {
            m[i] = m[i - 1] + -(long long)pow(2, i);
            p[i] = p[i - 1];
        }
    }
    int idx = 0;
    for (int i = 0; i < 40; i++) {
        if (n < 0) {
            if (m[i] <= n) {
                idx = i;
                break;
            }
        } else {
            if (p[i] >= n) {
                idx = i;
                break;
            }
        }
    }
    long long k = 0;
    for (int i = idx; i >= 0; i--) {
        if (i % 2 == 0) {
            if ((i == 0 && n - k == 1) || (i > 0 && k + p[i - 1] < n)) {
                cout << 1;
                k += (long long)pow(2, i);
            } else {
                cout << 0;
            }
        } else {
            if ((i == 0 && n - k == 1) || (i > 0 && m[i - 1] + k > n)) {
                k -= (long long)pow(2, i);
                cout << 1;
            } else {
                cout << 0;
            }
        }
    }
}