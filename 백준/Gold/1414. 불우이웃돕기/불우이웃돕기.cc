#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, map[51][51], parent[51];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    parent[a] = b;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char a;
            cin >> a;
            if (a == '0') {
                continue;
            }
            if (a <= 'Z') {
                map[i][j] = a - 'A' + 27;
            } else {
                map[i][j] = a - 'a' + 1;
            }
            v.push_back({map[i][j], {i, j}});
            ans += map[i][j];
        }
    }
    sort(v.begin(), v.end(), [](const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) -> bool { return p1.first < p2.first; });

    for (int i = 0; i < v.size(); i++) {
        int a = Find(v[i].second.first);
        int b = Find(v[i].second.second);

        if (a != b) {
            Union(a, b);
            ans -= v[i].first;
            cnt++;
        }
    }

    if (cnt != n - 1) {
        cout << -1;
    } else {
        cout << ans;
    }
}