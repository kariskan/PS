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

int p[300001];

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
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < n - 2; i++) {
        int a, b;
        cin >> a >> b;
        if (Find(a) != Find(b)) {
            Union(a, b);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            cout << i << ' ';
        }
    }
}