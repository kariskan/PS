#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[10001] = {0}, vis[10001] = {0};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int idx = 1, ans = 0;
        while (!vis[idx]) {
            vis[idx] = 1;
            if (idx == n) {
                break;
            }
            idx = a[idx];
            ans++;
        }
        if (vis[n]) {
            cout << ans << '\n';
        } else {
            cout << "0\n";
        }
    }
}