#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, p, k;
vector<vector<pair<int, int>>> v;
vector<int> cost;
int dis[1001][1001];

void go(int node, int cnt, int c, int now) {
    dis[node][cnt] = now;

    for (auto &i : v[node]) {
        if (i.second > c && cnt < k &&
            (dis[i.first][cnt + 1] == -1 || dis[i.first][cnt + 1] > now)) {
            go(i.first, cnt + 1, c, now);
        } else if (i.second <= c && (dis[i.first][cnt] == -1 ||
                                     dis[i.first][cnt] > max(now, i.second))) {
            go(i.first, cnt, c, max(now, i.second));
        }
    }
}

int main() {
    cin >> n >> p >> k;
    v.resize(n + 1);
    cost.push_back(0);
    for (int i = 0; i < p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        cost.push_back(c);
    }
    sort(cost.begin(), cost.end());

    int l = 0, r = cost.size() - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        memset(dis, -1, sizeof(dis));
        dis[1][0] = 0;
        go(1, 0, cost[mid], 0);
        bool flag = false;
        for (int i = 0; i <= k; i++) {
            if (dis[n][i] != -1) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            l = mid + 1;
        } else {
            ans = cost[mid];
            r = mid - 1;
        }
    }

    cout << ans;
}