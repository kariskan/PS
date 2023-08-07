#include <iostream>
using namespace std;

int a[30000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, k, c;
    // 접시 수, 초밥 가지 수, 연속해서 먹는 초밥 수, 쿠폰 번호
    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++) {
        cin >> a[i]; // 초밥
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int t = k, idx = i;
        int temp[3001] = {0};
        int tt = 0;
        while (t--) {
            if (!temp[a[idx]]) {
                tt++;
            }
            temp[a[idx]]++;
            idx = (idx + 1) % n;
        }

        ans = max(ans, temp[c] ? tt : tt + 1);
    }
    cout << ans;
}