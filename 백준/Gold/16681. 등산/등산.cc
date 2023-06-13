#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long n, m, d, e, h[100001];
vector<vector<pair<int, long long>>> v;
long long ans = LLONG_MIN;

vector<long long> dijk(int start) {
    vector<long long> dis(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>> pq;

    dis[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        long long cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dis[node]) {
            continue;
        }

        for (auto &i : v[node]) {
            int nxNode = i.first;
            long long nxCost = cost + i.second;
            if (dis[nxNode] > nxCost && h[nxNode] > h[node]) {
                dis[nxNode] = nxCost;
                pq.push({-nxCost, nxNode});
            }
        }
    }

    return dis;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> d >> e;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    vector<long long> disHome = dijk(1);
    vector<long long> disSchool = dijk(n);

    for (int i = 2; i < n; i++) {
        if (disHome[i] != LLONG_MAX && disSchool[i] != LLONG_MAX) {
            ans = max(ans, h[i] * e - (disHome[i] + disSchool[i]) * d);
        }
    }

    if (ans == LLONG_MIN) {
        cout << "Impossible";
    } else {
        cout << ans;
    }
}