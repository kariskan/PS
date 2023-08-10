#include <iostream>
using namespace std;

int n, a[1000001], b[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        a[c]++;
    }
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        b[c]++;
    }
    int ans = 0;
    for (int i = 1; i <= 1000000; i++) {
        a[i] -= min(a[i], b[i]);
        ans += a[i];
    }
    cout << ans;
}