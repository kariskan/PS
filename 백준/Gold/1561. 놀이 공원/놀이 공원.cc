#include <algorithm>
#include <iostream>
using namespace std;

int a[10000];

int main() {
    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    long long left = 0, right = *min_element(a, a + m) * (n + 1);
    long long ans = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += mid / a[j] + 1;
        }

        if (cnt >= n) {
            long long cnt2 = 0;
            for (int i = m - 1; i >= 0; i--) {
                cnt2 += mid / a[i];
                if (mid % a[i] != 0) {
                    cnt2++;
                }
            }
            for (int i = 0; i < m; i++) {
                if (n == cnt2) {
                    ans = i + 1;
                    break;
                }
                if (mid % a[i] == 0) {
                    cnt2++;
                }
                if (n == cnt2) {
                    ans = i + 1;
                    break;
                }
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans;
}