#include <iostream>
#include <vector>
using namespace std;

int n, k, a[101], vis[101];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int t = 1;; t++) {
        if (t > k) {
            cout << "NO";
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                continue;
            }
            int num = a[i];
            vis[i] = 1;
            cnt++;
            for (int j = i + 1; j <= n; j++) {
                if (!vis[j] && a[j] > num) {
                    vis[j] = 1;
                    cnt++;
                    num = a[j];
                }
            }
            break;
        }
        if (cnt == n) {
            break;
        }
    }
    cout << "YES";
}