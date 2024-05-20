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

using namespace std;

int vis[15], n, x, y, answer;

void go(int idx, vector<int> now) {
    if (idx > n) {
        answer++;
        return;
    }
    if (vis[idx]) {
        go(idx + 1, now);
        return;
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (i + idx + 1 <= 2 * n && now[i] == 0 && now[i + idx + 1] == 0) {
            now[i] = now[i + idx + 1] = idx;
            vis[idx] = 1;
            go(idx + 1, now);
            now[i] = now[i + idx + 1] = 0;
            vis[idx] = 0;
        }
    }
}

int main() {
    cin >> n >> x >> y;
    vis[y - x - 1] = 1;
    vector<int> now(2 * n + 1);
    now[x] = now[y] = y - x - 1;

    go(1, now);
    cout << answer;
}