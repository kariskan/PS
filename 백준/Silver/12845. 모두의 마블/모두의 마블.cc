#include <iostream>
using namespace std;

int n, a[1000];

int main() {
    cin >> n;
    int m = 0, s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = max(m, a[i]);
        s += a[i];
    }
    cout << m * (n - 1) + s - m;
}