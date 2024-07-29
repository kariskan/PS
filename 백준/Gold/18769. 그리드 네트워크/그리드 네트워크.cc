#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int p[250001];

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, pair<int, int> > > v;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                p[(i - 1) * m + j] = (i - 1) * m + j;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < m; j++) {
                int c;
                cin >> c;
                v.push_back({c, {(i - 1) * m + j, (i - 1) * m + j + 1}});
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                int c;
                cin >> c;
                v.push_back({c, {(i - 1) * m + j, i * m + j}});
            }
        }
        sort(v.begin(), v.end());

        int ans = 0;

        for (auto & i : v) {
            if (Find(i.second.first) != Find(i.second.second)) {
                Union(i.second.first, i.second.second);
                ans += i.first;
            }
        }
        cout << ans << '\n';
    }
}