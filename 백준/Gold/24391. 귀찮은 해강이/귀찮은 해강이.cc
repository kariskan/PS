#include <iostream>
using namespace std;

int p[100001];

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    p[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (Find(a) != Find(b)) {
            Union(a, b);
        }
    }
    int pre, ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (i == 1) {
            pre = a;
        } else {
            if (Find(pre) != Find(a)) {
                ans++;
            }
            pre = a;
        }
    }
    cout << ans;
}