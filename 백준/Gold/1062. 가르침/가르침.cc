#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int vis[26];
int n, k, ans;
vector<string> v;

void go(int cnt, int idx) {
    if (cnt == k) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            int len = v[i].length();
            for (int j = 4; j < len - 4; j++) {
                if (!vis[v[i][j] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                c++;
            }
        }
        ans = max(ans, c);
        return;
    }
    if (idx == 26) {
        return;
    }
    if (!vis[idx]) {
        vis[idx] = 1;
        go(cnt + 1, idx + 1);
        vis[idx] = 0;
    }
    go(cnt, idx + 1);
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    if (k < 5) {
        cout << 0;
        return 0;
    }
    vis[0] = vis['n' - 'a'] = vis['t' - 'a'] = vis['c' - 'a'] = vis['i' - 'a'] = 1;
    go(5, 0);
    cout << ans;
}