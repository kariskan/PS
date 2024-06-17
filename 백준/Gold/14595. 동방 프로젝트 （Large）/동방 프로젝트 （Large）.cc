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
#include <sstream>
#include <map>

using namespace std;

int p[1000001];

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
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<int> se;
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

    int mi = p[n];
    for (int i = n; i >= 1; i--) {
        mi = min(mi, Find(i));
        p[i] = mi;
    }

    for (int i = 1; i <= n; i++) {
        se.insert(Find(i));
    }
    cout << se.size();
}