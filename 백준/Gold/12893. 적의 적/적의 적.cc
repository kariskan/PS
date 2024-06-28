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

vector<vector<int>> v;
int n, m, vis[2001];

void go(int node, int pre, int c) {
    vis[node] = c;
    for (auto &i: v[node]) {
        if (i == pre) {
            continue;
        }
        if (vis[i] == c * -1) {
            continue;
        }
        if (vis[i] != 0 && vis[i] != c * -1) {
            cout << 0;
            exit(0);
        }
        go(i, node, c * -1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            go(i, 0, 1);
        }
    }
    cout << 1;
}