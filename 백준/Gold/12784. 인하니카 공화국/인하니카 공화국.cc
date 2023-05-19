#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int t, n, m, dp[1001], isLeaf[1001];
vector<vector<pair<int, int>>> v;

void checkLeaf(int node, int pre) {
    bool flag = false;
    for (auto &i : v[node]) {
        if (i.first != pre) {
            flag = true;
            checkLeaf(i.first, node);
        }
    }
    if (!flag) {
        isLeaf[node] = 1;
    }
}

int go(int node, int pre, int edge) {
    if (dp[node]) {
        return dp[node];
    }
    int res = 0;

    for (auto &i : v[node]) {
        if (i.first != pre) {
            if (isLeaf[i.first]) {
                res += i.second;
            } else {
                res += go(i.first, node, i.second);
            }
        }
    }

    return dp[node] = min(res, edge);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        v.clear();
        v.resize(n + 1);
        memset(isLeaf, 0, sizeof(isLeaf));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({b, c});
            v[b].push_back({a, c});
        }
        checkLeaf(1, 0);
        cout << go(1, 0, 1e9) << '\n';
        continue;
    }
}