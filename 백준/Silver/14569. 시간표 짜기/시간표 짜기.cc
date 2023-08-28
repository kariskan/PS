#include <iostream>
#include <vector>
using namespace std;

int ans[10000];

int main() {
    ios_base::sync_with_stdio(0);
    vector<int> v[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            v[i].push_back(b);
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        int vis[51] = {0};
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            vis[b] = 1;
        }
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int k = 0; k < v[j].size(); k++) {
                if (!vis[v[j][k]]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans[i]++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
}