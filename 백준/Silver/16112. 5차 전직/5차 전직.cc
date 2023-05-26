#include <algorithm>
#include <iostream>
using namespace std;
long long a[300000];
int main() {
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long ans = 0;
    for (long long i = 1; i < n; i++) {
        if (i < k) {
            ans += i * a[i];
        } else {
            ans += k * a[i];
        }
    }
    cout << ans;
}