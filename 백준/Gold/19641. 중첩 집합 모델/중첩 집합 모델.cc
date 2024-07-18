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

vector<vector<int> > v;
pair<int, int> ans[100001];
int seq = 1, n, s;

void go(int node, int pre) {
    if (node == 100001) {
        return;
    }
    int cnt = 0, last = 0;
    for (auto &i: v[node]) {
        if (i == pre) {
            continue;
        }
        cnt++;
        last = i;
        if (cnt == 1) {
            ans[node].first = seq++;
        }
        go(i, node);
    }
    ans[node].second = seq++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (1) {
            int b;
            cin >> b;
            if (b == -1) {
                break;
            }
            v[a].push_back(b);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
        v[i].push_back(100001);
        v[i].push_back(100001);
    }
    cin >> s;
    go(s, 0);
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << ans[i].first << ' ' << ans[i].second << '\n';
    }
}
