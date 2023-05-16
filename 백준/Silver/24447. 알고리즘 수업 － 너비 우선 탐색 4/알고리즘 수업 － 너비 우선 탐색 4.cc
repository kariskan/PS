#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long vis[100001];

int main() {
    long long n, m, r, seq = 1;
    cin >> n >> m >> r;
    vector<vector<long long>> v(n + 1);

    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    queue<long long> q;
    q.push(r);
    vis[r] = 1;
    long long ans = 0;

    while (!q.empty()) {
        long long node = q.front();
        q.pop();

        for (auto& i : v[node]) {
            if (!vis[i]) {
                vis[i] = vis[node] + 1;
                ans += (vis[i] - 1) * (++seq);
                q.push(i);
            }
        }
    }

    cout << ans;
}