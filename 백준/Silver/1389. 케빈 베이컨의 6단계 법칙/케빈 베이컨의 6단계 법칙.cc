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

int a[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }
                if (a[i][k] && a[k][j] && (a[i][j] == 0 || a[i][j] > a[i][k] + a[k][j])) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    int ans = 0, ansSum = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int j = 1; j <= n; j++) {
            s += a[i][j];
        }
        if (s < ansSum) {
            ans = i;
            ansSum = s;
        }
    }
    cout << ans;
}