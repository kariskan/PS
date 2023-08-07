#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int x = 0, y = 0;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            x = x * 10 + a;
        }
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            y = y * 10 + a;
        }
        int inp[100] = {0};
        for (int i = 0; i < n; i++) {
            cin >> inp[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = i, k = m;
            int sum = 0;
            while (k--) {
                sum = sum * 10 + inp[idx];
                idx = (idx + 1) % n;
            }
            if (sum >= x && sum <= y) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}