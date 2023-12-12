#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    vector<int> vis(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<int> q;

    q.push(1);
    vis[1] = 1;

    int ans = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (vis[node] == 3) {
            continue;
        }

        for (auto &i: v[node]) {
            if (!vis[i]) {
                vis[i] = vis[node] + 1;
                q.push(i);
                ans++;
            }
        }
    }

    cout << ans;
}