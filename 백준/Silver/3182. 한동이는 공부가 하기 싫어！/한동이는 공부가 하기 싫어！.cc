#include <cstring>
#include <iostream>
using namespace std;

int n, a[1001], vis[1001];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0, ansi = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        int idx = i, cnt = 0;
        while (!vis[idx]) {
            vis[idx] = 1;
            idx = a[idx];
            cnt++;
        }
        if (ans < cnt) {
            ans = cnt;
            ansi = i;
        }
    }
    cout << ansi;
}