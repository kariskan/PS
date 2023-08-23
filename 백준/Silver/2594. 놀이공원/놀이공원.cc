#include <algorithm>
#include <iostream>
using namespace std;

int n;
pair<int, int> a[50];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int b, c;
        cin >> b >> c;
        a[i] = {60 * (b / 100) + b % 100, 60 * (c / 100) + c % 100};
    }
    sort(a, a + n);

    int pre = 10 * 60, ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i].first - 10 - pre);
        pre = max(pre, a[i].second + 10);
    }
    ans = max(ans, 1320 - pre);
    cout << ans;
}