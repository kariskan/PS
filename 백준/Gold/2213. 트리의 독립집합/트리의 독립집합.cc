#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

int dp[10001][2], w[10001], n, vis[10001];
vector<vector<int> > v;
vector<int> ans;

int go(int node, int flag, int pre) {
    if (dp[node][flag]) {
        return dp[node][flag];
    }
    int res = 0;
    for (auto &i: v[node]) {
        if (i == pre) {
            continue;
        }
        if (flag) {
            res += go(i, 0, node);
        } else {
            res += max(go(i, 1, node), go(i, 0, node));
        }
    }
    return dp[node][flag] = res + (flag ? w[node] : 0);
}

/**
 * 1,10 -> 130, '140'
 * 2,30 -> '130', 120
 * 3,40 -> 20, '60'
 * 4,10 -> '20', 10
 * 5,20 -> 0, '20'
 * 6,20 -> '70', 20
 * 7,70 -> 0, '70'
 * 바로 전에 방문된 정점이 최대 독립 집합에 속하지 않음
 */
void go2(int node, int pre) {
    if (dp[node][1] > dp[node][0] && !vis[pre]) {
        ans.push_back(node);
        vis[node] = 1;
    }
    for (auto &i: v[node]) {
        if (i != pre) {
            go2(i, node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << max(go(1, 0, 0), go(1, 1, 0)) << '\n';
    go2(1, 0);
    sort(ans.begin(), ans.end());
    for (auto &i: ans) {
        cout << i << ' ';
    }
}
