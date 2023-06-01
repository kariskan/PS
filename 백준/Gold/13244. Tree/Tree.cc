#include <cstring>
#include <iostream>
using namespace std;

int t, n, m, p[1001];

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
    cin >> t;
    while (t--) {
        memset(p, 0, sizeof(p));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
        bool flag = true;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (Find(a) != Find(b)) {
                Union(a, b);
            } else {
                flag = false;
            }
        }
        if (flag && m == n - 1) {
            cout << "tree\n";
        } else {
            cout << "graph\n";
        }
    }
}