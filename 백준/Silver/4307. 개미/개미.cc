#include <iostream>
using namespace std;

int t;

int main() {
    cin >> t;
    while (t--) {
        int n, l;
        cin >> l >> n;
        int minans = -1, maxans = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            minans = max(minans, min(a, l - a));
            maxans = max(maxans, max(a, l - a));
        }
        cout << minans << ' ' << maxans << '\n';
    }
}