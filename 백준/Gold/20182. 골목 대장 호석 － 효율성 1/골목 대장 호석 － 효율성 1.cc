#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <mutex>
using namespace std;

int n, m, a, b, c;
vector<vector<pair<int, int> > > v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b >> c;
    v.resize(n + 1);
    int l = 20, r = 1;
    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v[v1].push_back({v2, w});
        v[v2].push_back({v1, w});
        l = min(l, w);
        r = max(r, w);
    }

    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        priority_queue<pair<int, int> > pq;
        vector<int> dis(n + 1, 1e9);

        pq.push({0, a});
        dis[a] = 0;

        while (!pq.empty()) {
            int cost = -pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &i: v[node]) {
                int nxCost = cost + i.second;
                int nxNode = i.first;
                if (dis[nxNode] > nxCost && i.second <= mid) {
                    dis[nxNode] = nxCost;
                    pq.push({-nxCost, nxNode});
                }
            }
        }

        if (dis[b] <= c) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
}
