#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, p[1025];
vector<pair<int, pair<int, int>>> v;
vector<vector<int>> ans;

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    p[a] = b;
}

int main() {
    cin >> n;
    ans.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int a;
            cin >> a;
            v.push_back({a, {i, j}});
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        int a = Find(v[i].second.first);
        int b = Find(v[i].second.second);
        if (a != b) {
            Union(a, b);
            ans[v[i].second.first].push_back(v[i].second.second);
            ans[v[i].second.second].push_back(v[i].second.first);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i].size() << ' ';
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}