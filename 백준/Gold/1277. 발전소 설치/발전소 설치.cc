#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
int n, w;
double m;
vector<vector<pair<int, double> > > v;
pair<ll, ll> coor[1001];

double getDistance(int i, int j) {
    return sqrt(
        (coor[i].first - coor[j].first) * (coor[i].first - coor[j].first) +
        (coor[i].second - coor[j].second) * (coor[i].second - coor[j].second)
    );
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w >> m;
    for (int i = 1; i <= n; i++) {
        cin >> coor[i].first >> coor[i].second;
    }
    v.resize(n + 1);
    for (int i = 0; i < w; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back({b, 0});
        v[b].push_back({a, 0});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double dis = getDistance(i, j);
            if (dis <= m) {
                v[i].push_back({j, dis});
                v[j].push_back({i, dis});
            }
        }
    }

    vector<double> dis(n + 1, -1);
    priority_queue<pair<double, int> > q;

    q.push({0, 1});
    dis[1] = 0;

    while (!q.empty()) {
        double cost = -q.top().first;
        int node = q.top().second;
        q.pop();

        if (dis[node] < cost) {
            continue;
        }

        for (auto &i: v[node]) {
            double nxCost = i.second + cost;
            int nxNode = i.first;
            if (dis[nxNode] == -1 || nxCost < dis[nxNode]) {
                dis[nxNode] = nxCost;
                q.push({-nxCost, nxNode});
            }
        }
    }
    cout << (long) (dis[n] * 1000);
}
