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

int n, p[301];

int Find(int x) {
    if (x == p[x]) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<pair<int, pair<int, int> > > v;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        int w;
        cin >> w;
        v.push_back({w, {0, i}});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int b;
            cin >> b;
            if (i > j) {
                v.push_back({b, {i, j}});
            }
        }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (auto &i: v) {
        int n1 = Find(i.second.first);
        int n2 = Find(i.second.second);
        int cost = i.first;
        if (n1 != n2) {
            Union(n1, n2);
            ans += cost;
        }
    }
    cout << ans;
}