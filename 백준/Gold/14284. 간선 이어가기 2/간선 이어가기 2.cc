#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > v(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    int x, y;
    cin >> x >> y;

    vector<int> dis(n + 1,INT_MAX);
    priority_queue<pair<int, int> > pq;

    pq.push({0, x});
    dis[x] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for (auto &i: v[node]) {
            int nxCost = cost + i.second;
            if (dis[i.first] > nxCost) {
                dis[i.first] = nxCost;
                pq.push({-nxCost, i.first});
            }
        }
    }

    cout << dis[y];
}
