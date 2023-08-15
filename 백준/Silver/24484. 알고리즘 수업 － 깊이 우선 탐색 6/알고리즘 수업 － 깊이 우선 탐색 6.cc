#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
long long n, m, r, vis[100001], t;
long long ans;

void dfs(int node, int depth) {
    vis[node] = 1;
    t++;
    ans += t * depth;
    for (auto &i : v[node]) {
        if (!vis[-i]) {
            dfs(-i, depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(-b);
        v[b].push_back(-a);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    dfs(r, 0);
    cout << ans;
}