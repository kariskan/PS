#include <iostream>
#include <vector>
using namespace std;

int n, energy[100001], vis[100001];
vector<vector<pair<int, int>>> v;
pair<long long, long long> tbl[18][100001];

void go(int node, int pre) {
    vis[node] = 1;
    for (auto &i : v[node]) {
        if (!vis[i.first]) {
            go(i.first, node);
            tbl[0][i.first] = {node, i.second};
        }
    }
}

int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> energy[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    go(1, 0);

    for (int i = 1; i <= 17; i++) {
        for (int j = 1; j <= n; j++) {
            tbl[i][j].first = tbl[i - 1][tbl[i - 1][j].first].first;
            tbl[i][j].second +=
                tbl[i - 1][j].second + tbl[i - 1][tbl[i - 1][j].first].second;
        }
    }

    for (int i = 1; i <= n; i++) {
        int idx = i;
        for (int j = 17; j >= 0; j--) {
            if (tbl[j][idx].first != 0 && tbl[j][idx].second <= energy[i]) {
                energy[i] -= tbl[j][idx].second;
                idx = tbl[j][idx].first;
            }
        }
        cout << idx << '\n';
    }
}