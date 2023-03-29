#include <iostream>
using namespace std;

long long n, k, a[1000001], q, inp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        inp[c]++;
    }
    for (int i = 1; i <= n; i++) {
        if (inp[i]) {
            int idx = 0;
            while (idx < n) {
                a[idx] += inp[i];
                idx += i;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == 0) {
            cout << a[r] << '\n';
        } else {
            cout << a[r] - a[l - 1] << '\n';
        }
    }
}