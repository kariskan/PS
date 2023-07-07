#include <iostream>
using namespace std;

int n, m, q;
pair<int, int> inp[100001];
int disconnect[100001], p[100001], notPreConnected[100001];
long long ans, cnt[100001];

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a < b) {
        p[b] = a;
    } else {
        p[a] = b;
    }
    ans += cnt[a] * cnt[b];
    cnt[a] += cnt[b];
    cnt[b] = cnt[a];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> inp[i].first >> inp[i].second;
    }
    for (int i = 0; i < q; i++) {
        cin >> disconnect[i];
        notPreConnected[disconnect[i]] = 1;
    }
    for (int i = 1; i <= m; i++) {
        if (notPreConnected[i] == 0) {
            int n1 = Find(inp[i].first);
            int n2 = Find(inp[i].second);
            if (n1 != n2) {
                Union(n1, n2);
            }
        }
    }
    ans = 0;

    for (int i = q - 1; i >= 0; i--) {
        int n1 = Find(inp[disconnect[i]].first);
        int n2 = Find(inp[disconnect[i]].second);

        if (n1 != n2) {
            Union(n1, n2);
        }
    }

    cout << ans;
}