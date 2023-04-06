#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k, p[1000], ans1, ans2;
vector<vector<pair<int, int>>> v;
vector<pair<int, pair<int, int>>> inp;

void dfs(int node, int pre, int cost) {
    if (ans2 < cost) {
        ans2 = cost;
    }

    for (auto& i : v[node]) {
        if (i.first != pre) {
            dfs(i.first, node, cost + i.second);
        }
    }
}

int Find(int x) {
    if (p[x] == x) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    p[a] = b;
}

int main() {
    cin >> n >> k;

    v.resize(n);

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        inp.push_back({c, {a, b}});
    }

    sort(inp.begin(), inp.end());

    for (int i = 0; i < inp.size(); i++) {
        int a = inp[i].second.first;
        int b = inp[i].second.second;
        if (Find(a) != Find(b)) {
            Union(a, b);

            v[a].push_back({b, inp[i].first});
            v[b].push_back({a, inp[i].first});
            ans1 += inp[i].first;
        }
    }

    for (int i = 0; i < n; i++) {
        dfs(i, -1, 0);
    }

    cout << ans1 << '\n' << ans2;
}