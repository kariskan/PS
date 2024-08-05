#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int vis[13];
vector<pair<int, int> > house, chicken;
int n, m, ans = INT_MAX;

void go(int idx, int cnt) {
    if (cnt == m) {
        int temp = 0;
        for (int i = 0; i < house.size(); i++) {
            int chickenDis = INT_MAX;
            for (int j = 0; j < chicken.size(); j++) {
                if (vis[j] == 0) {
                    continue;
                }
                chickenDis = min(
                    chickenDis, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
            }
            temp += chickenDis;
        }
        ans = min(ans, temp);
        return;
    }
    if (idx >= chicken.size()) {
        return;
    }

    go(idx + 1, cnt);
    vis[idx] = 1;
    go(idx + 1, cnt + 1);
    vis[idx] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            if (b == 1) {
                house.push_back({i, j});
            } else if (b == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    go(0, 0);
    cout << ans;
}