#include <iostream>
using namespace std;

int n, m, a[101], ans;

void go(int now, int idx, int cnt) {
    ans = max(ans, now);
    if (cnt == m) {
        return;
    }
    
    if (idx <= n - 2) {
        go(now / 2 + a[idx + 2], idx + 2, cnt + 1);
    }
    if (idx <= n - 1) {
        go(now + a[idx + 1], idx + 1, cnt + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    go(1, 0, 0);

    cout << ans;
}