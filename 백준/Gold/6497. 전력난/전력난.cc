#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;
vector<int> p;

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
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

    while (1) {
        vector<pair<int, pair<int, int>>> v;

        int n, m;
        cin >> n >> m;
        if (n == 0) {
            return 0;
        }
        p.clear();
        p.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            ans += c;
            v.push_back({c, {a, b}});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < m; i++) {
            if (Find(v[i].second.first) != Find(v[i].second.second)) {
                Union(v[i].second.first, v[i].second.second);
                ans -= v[i].first;
            }
        }
        cout << ans << '\n';
    }
}