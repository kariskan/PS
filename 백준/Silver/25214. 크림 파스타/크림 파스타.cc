#include <iostream>
using namespace std;

int n, a[200000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int mi = 1000000001, pre = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mi = min(mi, a[i]);
        cout << max(a[i] - mi, pre) << ' ';
        pre = max(pre, a[i] - mi);
    }
}