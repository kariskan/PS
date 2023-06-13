#include <algorithm>
#include <iostream>
using namespace std;

int n;
pair<int, int> a[100002];
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a + 1, a + n + 1);
    a[0] = {-1, -1};
    for (int i = 1; i <= n; i++) {
        if (a[i].first != a[i - 1].first && a[i].first != a[i + 1].first) {
            continue;
        } else if (a[i].first != a[i - 1].first) {
            ans += abs(a[i].second - a[i + 1].second);
        } else if (a[i].first != a[i + 1].first) {
            ans += abs(a[i].second - a[i - 1].second);
        } else {
            ans += min(abs(a[i].second - a[i - 1].second), abs(a[i].second - a[i + 1].second));
        }
    }
    
    cout << ans;
}