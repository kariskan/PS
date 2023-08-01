#include <iostream>
#include <vector>
using namespace std;

int vis[101];
vector<vector<int>> v;

void go(int node) {
    vis[node] = 1;
    for (auto &i : v[node]) {
        if (vis[i]) {
            cout << "CYCLE";
            exit(0);
        }
        go(i);
    }
    vis[node] = 0;
}

int main() {
    int n;
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    go(1);
    cout << "NO CYCLE";
}