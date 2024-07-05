#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int n, k, p[1001], lastNode, maxWeight;
vector<vector<pair<int, int> > > ad;
vector<pair<int, pair<int, int> > > v;

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

int dfs(int node, int pre, int w) {
    if (w > maxWeight) {
        maxWeight = w;
        lastNode = node;
    }
    int res = 0;
    for (auto &i: ad[node]) {
        if (i.first == pre) {
            continue;
        }
        res = max(res, dfs(i.first, node, w + i.second));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    ad.resize(n + 1);

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a + 1, b + 1}});
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b) { return a.first < b.first; });
    int ans1 = 0;
    for (auto &i: v) {
        if (Find(i.second.first) != Find(i.second.second)) {
            Union(i.second.first, i.second.second);
            ans1 += i.first;
            ad[i.second.first].push_back({i.second.second, i.first});
            ad[i.second.second].push_back({i.second.first, i.first});
        }
    }

    cout << ans1 << '\n';
    dfs(1, 0, 0);
    dfs(lastNode, 0, 0);
    cout << maxWeight;
}
