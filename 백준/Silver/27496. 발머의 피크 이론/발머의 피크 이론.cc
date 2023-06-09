#include <iostream>
using namespace std;

int n, l, a[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    int ans = 0;
    int al = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        al += a[i];
        if (i - l >= 0) {
            al -= a[i - l];
        }
        if (al >= 129 && al <= 138) {
            ans++;
        }
    }
    cout << ans;
}