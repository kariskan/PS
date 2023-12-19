#include <iostream>
#include <climits>

using namespace std;

long long n, m, a[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long l = 0, r = 2000000000, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max((long long) 0, a[i] - mid);
        }
        if (sum < m) {
            r = mid - 1;
        } else {
            l = mid + 1;
            ans = max(ans, mid);
        }
    }
    cout << ans;
}