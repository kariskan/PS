#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, r, depth[100001];
vector<vector<int>> v;

void go(int node, int d) {
    depth[node] = d;

    for (auto &i : v[node]) {
        if (!depth[i]) {
            go(i, d + 1);
        }
    }
}

int main() {
    cin >> n >> m >> r;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    go(r, 1);

    for (int i = 1; i <= n; i++) {
        cout << depth[i] - 1 << '\n';
    }
}