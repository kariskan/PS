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

int a[10000], tree[10000], n, inp = 1;

void traversal(int idx) {
    if (idx >= (1 << n)) {
        return;
    }
    traversal(idx * 2);
    tree[idx] = a[inp++];
    traversal(idx * 2 + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < (1 << n); i++) {
        cin >> a[i];
    }
    traversal(1);
    int idx = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << i); j++) {
            cout << tree[idx++] << ' ';
        }
        cout << '\n';
    }
}