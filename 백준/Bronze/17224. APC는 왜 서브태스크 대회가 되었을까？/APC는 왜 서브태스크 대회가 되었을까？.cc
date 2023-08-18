#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

pair<int, int> a[100];

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, compare);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second <= l) {
            ans += 140;
            k--;
        } else {
            if (a[i].first <= l) {
                ans += 100;
                k--;
            }
        }
        if (k == 0) {
            break;
        }
    }
    cout << ans;
}