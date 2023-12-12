#include <iostream>
#include <algorithm>

using namespace std;

long long a[1000000], b[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b, b + m);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1;
            long long temp = 2000000000, num;
            while (left <= right) {
                int mid = (left + right) / 2;

                if (temp > abs(a[i] - b[mid])) {
                    temp = abs(a[i] - b[mid]);
                    num = b[mid];
                } else if (temp == abs(a[i] - b[mid])) {
                    if (num > b[mid]) {
                        num = b[mid];
                    }
                }
                if (a[i] > b[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans += num;
        }
        cout << ans << '\n';
    }
}