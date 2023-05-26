#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> v(n + 1);
    vector<int> vis(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vis[r] = 1;
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto &i : v[node]) {
            if (!vis[i]) {
                vis[i] = vis[node] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            cout << vis[i] - 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}