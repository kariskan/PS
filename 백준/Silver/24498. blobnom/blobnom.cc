#include <iostream>
using namespace std;

int n, a[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, a[i] + min(a[i - 1], a[i + 1]));
    }

    cout << max(ans, max(a[0], a[n - 1]));
}