#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>

using namespace std;

string s[500001];
string ans;
int in[500001], vis[500001];
vector<vector<pair<int, int>>> v;

void go(int now) {
    vis[now] = 1;
    ans += s[now];
    for (auto &i: v[now]) {
        if (!vis[i.second]) {
            go(i.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        in[b]++;
        v[a].push_back({i, b});
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            go(i);
            break;
        }
    }
    cout << ans;
}