#include <algorithm>
#include <iostream>
using namespace std;

int n, a[10001], s[10002];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        int p = a[i], idx = 1;
        while (idx <= n && p) {
            if (idx == i) {
                idx++;
                continue;
            }
            s[idx++]++;
            p--;
        }
        if (p) {
            cout << -1;
            return 0;
        }
    }
    int p = 0;
    for (int i = 1; i <= n; i++) {
        int mi = min(s[i], n - 1 - a[i]);
        s[i + 1] += s[i] - mi;
        s[i] = mi;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] + a[i] != n - 1) {
            cout << -1;
            return 0;
        }
    }
    if (s[n + 1]) {
        cout << -1;
        return 0;
    }
    cout << 1;
}