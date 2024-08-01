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

int p[1001];

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

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        p[a] = 0;
    }

    vector<pair<int, pair<int, int> > > v;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (auto & i : v) {
        int n1 = Find(i.second.first);
        int n2 = Find(i.second.second);
        if (n1 != n2) {
            Union(n1, n2);
            ans += i.first;
        }
    }
    cout << ans;
}