#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int a[100][10000], idx[100][1000001], c[100][10000];
vector<int> b[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i].push_back(a[i][j]);
        }
        sort(b[i].begin(), b[i].end());
        b[i].erase(unique(b[i].begin(), b[i].end()), b[i].end());
        for (int j = 0; j < b[i].size(); j++) {
            if (idx[i][b[i][j]] == 0) {
                idx[i][b[i][j]] = j + 1;
            } else {
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 0) {
                c[i][j] = idx[i][a[i][j]];
            } else {
                c[i][j] = min(c[i][j], idx[i][a[i][j]]);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool flag = true;
            for (int k = 0; k < m; k++) {
                if (c[i][k] != c[j][k] || b[i].size() != b[j].size()) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
    }

    cout << ans;
}