#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, long long>>> v;
vector<long long> dis, dp, child;
int n;

void go(int node, int pre, long long sum) {
    dis[node] = sum;
    for (auto &i : v[node]) {
        if (i.first != pre) {
            go(i.first, node, sum + i.second);
        }
    }
}

int getChild(int node, int pre) {
    bool flag = false;
    int res = 0;
    for (auto &i : v[node]) {
        if (i.first != pre) {
            flag = true;
            res += getChild(i.first, node);
        }
    }
    return child[node] = res + 1;
}

void go2(int node, int pre, long long now) {
    dp[node] = now;
    for (auto &i : v[node]) {
        if (i.first != pre) {
            long long c = child[i.first];
            go2(i.first, node, now + (n - c) * i.second - c * i.second);
        }
    }
}

int main() {
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        dis.clear();
        dis.resize(n);
        v.clear();
        v.resize(n);
        dp.clear();
        dp.resize(n);
        child.clear();
        child.resize(n);

        for (int i = 0; i < n - 1; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({b, c});
            v[b].push_back({a, c});
        }
        go(0, -1, 0);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += dis[i];
        }
        getChild(0, -1);
        go2(0, -1, sum);
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i]);
        }
        cout << ans << '\n';
    }
}