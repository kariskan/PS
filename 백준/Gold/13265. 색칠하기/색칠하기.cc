#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
vector<vector<int>> v;
vector<int> c;
bool flag;

void dfs(int node, int color) {
    for (auto &i : v[node]) {
        if (node == i) {
            continue;
        }
        if (!c[i]) {
            if (color == 1) {
                c[i] = 2;
                dfs(i, 2);
            } else {
                c[i] = 1;
                dfs(i, 1);
            }
        } else {
            if (color == c[i]) {
                flag = false;
                return;
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        v.clear();
        v.resize(n + 1);
        c.clear();
        c.resize(n + 1);
        flag = true;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (!c[i]) {
                c[i] = 1;
                dfs(i, 1);
            }
        }

        if (flag) {
            cout << "possible\n";
        } else {
            cout << "impossible\n";
        }
    }
}