#include <iostream>
using namespace std;

int n, m, a[151], vis[151];

void go(int now, int cnt) {
    vis[now] = 1;
    if (now == m) {
        cout << cnt;
        exit(0);
    }
    if (!vis[a[now]]) {
        go(a[now], cnt + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    go(0, 0);
    cout << -1;
}