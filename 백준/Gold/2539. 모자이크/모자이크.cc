#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, c, k;
vector<int> y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> c >> k;
    int h = 0;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        h = max(h, a);
        y.push_back(b);
    }
    sort(y.begin(), y.end());
    int l = h, r = 1000000, ans = 1000000;
    while (l <= r) {
        int mid = (l + r) / 2;

        int cnt = 0, pre = -1;
        for (int i = 0; i < y.size(); i++) {
            if (pre == -1 || pre + mid <= y[i]) {
                pre = y[i];
                cnt++;
            }
        }
        if (cnt <= c) {
            r = mid - 1;
            ans = min(ans, mid);
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}