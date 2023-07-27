#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> v;
long long p[100001], s[100001];
long long mod = 1e9;

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    p[b] = a;
    s[a] += s[b];
    s[b] = 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        p[i] = i;
        s[i] = 1;
    }
    long long total = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
        total += c;
    }
    sort(v.begin(), v.end(),
         [](auto v1, auto v2) { return v1.first > v2.first; });
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int cost = v[i].first;
        int n1 = v[i].second.first;
        int n2 = v[i].second.second;
        int pn1 = Find(n1);
        int pn2 = Find(n2);
        if (pn1 != pn2) {
            ans += (((s[pn1] * s[pn2]) % mod) * total) % mod;
            ans %= mod;
            Union(pn1, pn2);
        }
        total -= cost;
    }
    cout << ans;
}