#include <algorithm>
#include <iostream>
using namespace std;

int d, n, m, a[50000];

int main() {
    cin >> d >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int left = 1, right = d;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;

        int last = 0, cnt = m;
        for (int i = 0; i < n; i++) {
            if (a[i] - last < mid) {
                cnt--;
                continue;
            }
            last = a[i];
        }

        if (d - last < mid) {
            cnt--;
        }

        if (cnt >= 0) {
            left = mid + 1;
            ans = max(ans, mid);
        } else {
            right = mid - 1;
        }
    }

    cout << ans;
}