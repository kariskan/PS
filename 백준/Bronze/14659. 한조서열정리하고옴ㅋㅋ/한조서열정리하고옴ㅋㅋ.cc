#include <iostream>
using namespace std;

int n, a[30000], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            cnt = 0;
        } else {
            cnt++;
        }
        m = max(m, a[i]);
        ans = max(ans, cnt);
    }
    cout << ans;
}