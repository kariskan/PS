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

int n, vis[30][30];
double a[4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
double ans;

void go(double r, int x, int y, int c) {
    if (c == n) {
        ans += r;
        return;
    }
    for (int k = 0; k < 4; k++) {
        if (a[k] > 0) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!vis[nx][ny]) {
                vis[nx][ny] = 1;
                go(r * a[k], nx, ny, c + 1);
                vis[nx][ny] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
        a[i] /= 100;
    }
    vis[15][15] = 1;
    go(1, 15, 15, 0);
    cout << fixed;
    cout.precision(9);
    cout << ans;
}