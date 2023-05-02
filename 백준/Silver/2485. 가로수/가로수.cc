#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int a[100000], diff[100000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i - 1];
    }
    int g = diff[1];
    for (int i = 2; i < n; i++) {
        g = gcd(g, diff[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += diff[i] / g - 1;
    }
    cout << ans;
}