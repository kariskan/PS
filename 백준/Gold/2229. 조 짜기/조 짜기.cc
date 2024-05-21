#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n, a[1001], dp[1001][1001];

int get(int l, int r) {
    int ma = 0, mi = 10000;
    for (int i = l; i <= r; i++) {
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    return ma - mi;
}

int go(int l, int r) {
    if (l >= r) {
        return dp[l][r] = 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    int res = get(l, r);
    for (int i = l + 1; i <= r - 1; i++) {
        res = max(res, go(l, i) + go(i + 1, r));
    }
    return dp[l][r] = res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << go(1, n);
}