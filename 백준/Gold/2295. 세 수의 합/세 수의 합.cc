#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1000];
vector<pair<int, pair<int, int>>> p;
vector<pair<int, pair<int, int>>> m;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            p.push_back({a[i] + a[j], {min(a[i], a[j]), max(a[j], a[i])}});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            m.push_back({abs(a[i] - a[j]), {min(a[i], a[j]), max(a[i], a[j])}});
        }
    }

    sort(p.begin(), p.end());
    sort(m.begin(), m.end());

    int pi = p.size() - 1, mi = m.size() - 1;
    int ans = 0;

    while (pi >= 0 && mi >= 0) {
        if (p[pi].first == m[mi].first) {
            ans = max(ans, m[mi].second.second);
        }

        if (p[pi].first >= m[mi].first) {
            if (pi > 0) {
                pi--;
            } else {
                break;
            }
        } else {
            if (mi > 0) {
                mi--;
            } else {
                break;
            }
        }
    }

    cout << ans;
}