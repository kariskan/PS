#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int n, a[5000], dp[5000][5000];
// dp[i][j] = [i, j]의 수열에서 팰린드롬을 만들려고 할 때 끼워 넣어야 하는 수들의 최소 개수

int go(int l, int r) {
    if (l >= r) {
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    int res = INT_MAX;
    if (a[l] == a[r]) {
        res = min(res, go(l + 1, r - 1));
    }
    res = min(res, min(1 + go(l, r - 1), 1 + go(l + 1, r)));
    return dp[l][r] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    cout << go(0, n - 1);
}
