#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, m, p[100001], a[100001];
map<int, int> ma;

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (a[x] > a[y]) {
        a[x] += a[y];
        p[y] = x;
    } else {
        a[y] += a[x];
        p[x] = y;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int o, pa, q;
        cin >> o >> pa >> q;
        if (o == 1) {
            Union(pa, q);
        } else {
            int fp = Find(pa);
            int fq = Find(q);
            if (a[fp] > a[fq]) {
                a[fp] -= a[fq];
                p[fq] = fp;
            } else if (a[fp] < a[fq]) {
                a[fq] -= a[fp];
                p[fp] = fq;
            } else {
                a[fp] = a[fq] = p[fp] = p[fq] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int ip = Find(i);
        if (ip != 0) {
            ma[ip] = a[ip];
        }
    }
    cout << ma.size() << '\n';
    vector<int> v;
    for (auto &i : ma) {
        v.push_back(i.second);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}