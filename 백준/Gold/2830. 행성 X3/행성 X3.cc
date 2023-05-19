#include <iostream>
using namespace std;

long long a[20], n;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int j = 0;
        while (k) {
            if (k % 2 == 1) {
                a[j]++;
            }
            j++;
            k /= 2;
        }
    }

    for (int i = 0; i < 20; i++) {
        ans += (1 << i) * a[i] * (n - a[i]);
    }

    cout << ans;
}
