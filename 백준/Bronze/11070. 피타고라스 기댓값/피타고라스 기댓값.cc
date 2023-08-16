#include <iostream>
#include <cstring>
using namespace std;

int t, n, m;
pair<int, int> a[1001];

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; i++) {
            int b, c, d, e;
            cin >> b >> c >> d >> e;
            a[b].first += d;
            a[b].second += e;
            a[c].first += e;
            a[c].second += d;
        }
        double mi = 1000000000;
        double ma = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].first == 0 && a[i].second == 0) {
                mi = 0;
                continue;
            }
            int total = a[i].first * a[i].first;
            int lose = a[i].second * a[i].second;
            mi = min(mi, total / (double)(total + lose) * 1.0);
            ma = max(ma, total / (double)(total + lose) * 1.0);
        }
        cout << (int)(ma * 1000) << ' ' << (int)(mi * 1000) << '\n';
    }
}