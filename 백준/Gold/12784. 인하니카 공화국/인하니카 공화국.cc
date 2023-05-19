#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n, m, one[1001];
vector<vector<pair<int, int>>> v;

void go(int node, int pre) {
    bool flag = false;
    for (auto &i : v[node]) {
        if (i.first != pre) {
            go(i.first, node);
            flag = true;
        }
    }
    if (!flag) {
        one[node] = 1;
    }
}

int go2(int node, int pre, int edge) {
    int res = 0;
    for (auto &i : v[node]) {
        if (i.first != pre) {
            if (one[i.first]) {
                res += i.second;
            } else {
                res += go2(i.first, node, i.second);
            }
        }
    }
    return min(edge, res);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        v.clear();
        v.resize(n + 1);
        memset(one, 0, sizeof(one));

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({b, c});
            v[b].push_back({a, c});
        }
        
        go(1, 0);
        cout << go2(1, 0, 1e9) << '\n';
    }
}