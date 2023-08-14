#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> v(1001);
int n, m, pre[1001];

vector<int> dijk(int k) {
    vector<int> dis(n + 1, 987654321);
    priority_queue<pair<int, int>> q;
    dis[1] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        int cost = -q.top().first;
        int node = q.top().second;
        q.pop();
        
        if (cost > dis[node]) {
            continue;
        }

        for (auto &i : v[node]) {
            int nxNode = i.first;
            int nxCost = cost + i.second;
            
            if ((node == k && pre[node] == nxNode) || (nxNode == k && pre[nxNode] == node)) {
                continue;
            }
            if (nxCost < dis[nxNode]) {
                if (k == 0) {
                    pre[nxNode] = node;
                }
                dis[nxNode] = nxCost;
                q.push({-nxCost, nxNode});
            }
        }
    }
    return dis;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dijk(0);
    int ans = 0;
    for (int i = n; i > 1;) {
        vector<int> dis = dijk(i);
        i = pre[i];
        ans = max(ans, dis[n]);
    }
    cout << ans;
}