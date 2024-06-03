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

int n, a[8], p, q, ans;

void go(vector<int> v) {
    if (v.size() == n - 1) {
        int total = 1, temp = a[0];
        vector<int> c;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == 1) {
                c.push_back(temp);
                temp = 0;
            }
            temp += a[i + 1];
        }
        if (temp != 0) {
            c.push_back(temp);
        }
        for (int i = 0; i < c.size(); i++) {
            total *= c[i];
        }
        ans = max(ans, total);
        return;
    }

    if (p > 0) {
        p--;
        v.push_back(0);
        go(v);
        v.pop_back();
        p++;
    }
    if (q > 0) {
        q--;
        v.push_back(1);
        go(v);
        v.pop_back();
        q++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> p >> q;
    sort(a, a + n);
    do {
        go({});
    } while (next_permutation(a, a + n));
    cout << ans;
}