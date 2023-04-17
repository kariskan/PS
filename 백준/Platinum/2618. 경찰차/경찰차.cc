#include <algorithm>
#include <iostream>
using namespace std;

int n, w;
pair<int, int> a[1001];
int dp[1001][1001];

int go(int i, int j) {
    if (max(i, j) >= w) {
        return 0;
    }

    if (dp[i][j]) {
        return dp[i][j];
    }

    int next = max(i, j) + 1;
    int res1, res2;
    if (i == 0) {
        res1 = a[next].first + a[next].second - 2;
    } else {
        res1 = abs(a[next].first - a[i].first) + abs(a[next].second - a[i].second);
    }
    if (j == 0) {
        res2 = 2 * n - a[next].first - a[next].second;
    } else {
        res2 = abs(a[next].first - a[j].first) + abs(a[next].second - a[j].second);
    }

    return dp[i][j] = min(res1 + go(next, j), res2 + go(i, next));
}

void go2(int i, int j) {
    if (max(i, j) >= w) {
        return;
    }

    int next = max(i, j) + 1;

    int res1, res2;
    if (i == 0) {
        res1 = a[next].first + a[next].second - 2;
    } else {
        res1 = abs(a[next].first - a[i].first) + abs(a[next].second - a[i].second);
    }
    if (j == 0) {
        res2 = 2 * n - a[next].first - a[next].second;
    } else {
        res2 = abs(a[next].first - a[j].first) + abs(a[next].second - a[j].second);
    }

    int ret1 = res1 + go(next, j);
    int ret2 = res2 + go(i, next);

    if (ret1 < ret2) {
        cout << "1\n";
        go2(next, j);
    } else {
        cout << "2\n";
        go2(i, next);
    }
}

int main() {
    cin >> n >> w;

    for (int i = 1; i <= w; i++) {
        cin >> a[i].first >> a[i].second;
    }

    cout << go(0, 0) << '\n';
    go2(0, 0);
}