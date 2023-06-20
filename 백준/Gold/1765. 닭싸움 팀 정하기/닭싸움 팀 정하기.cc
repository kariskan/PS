#include <iostream>
#include <vector>
using namespace std;

int n, m, vis[1001];
vector<vector<pair<int, int>>> v;

void go(int node) {
    vis[node] = 1;

    for (auto &i : v[node]) {
        if (!vis[i.first] && i.second == 1) {
            go(i.first);
        } else if (i.second == 0) {
            for (auto &j : v[i.first]) {
                if (!vis[j.first] && j.second == 0) {
                    go(j.first);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        if (a == 'E') {
            v[b].push_back({c, 0});
            v[c].push_back({b, 0});
        } else {
            v[b].push_back({c, 1});
            v[c].push_back({b, 1});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            go(i);
            ans++;
        }
    }

    cout << ans;
}