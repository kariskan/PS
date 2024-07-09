#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int n, t, root, maxVC, ans = -1;
vector<vector<pair<int, int> > > v;

void dfs(int node, int pre, int count, int weight) {
    if (count >= maxVC) {
        if (count > maxVC || (count == maxVC && ans > (weight + t - 1) / t)) {
            ans = (weight + t - 1) / t;
            root = node;
            maxVC = count;
        }
    }
    for (auto &i: v[node]) {
        if (i.first != pre) {
            dfs(i.first, node, count + 1, weight + i.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dfs(1, 0, 1, 0);
    ans = 0;
    maxVC = 0;
    dfs(root, 0, 1, 0);
    cout << ans;
}