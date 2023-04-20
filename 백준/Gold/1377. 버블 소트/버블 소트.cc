#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> a[500001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i].second - i + 1);
    }

    cout << ans;
}