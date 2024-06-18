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

int a[101], vis[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int x, y;
        cin >> x >> y;
        a[x] = y;
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        int now = q.front();
//        cout << now << ' ' << vis[now]<<'\n';
        q.pop();

        if (a[now] > 0) {
            if (vis[a[now]] == 0 || vis[a[now]] > vis[now]) {
                vis[a[now]] = vis[now];
                q.push(a[now]);
            }
            continue;
        }
        for (int i = 1; i <= 6; i++) {
            int next = now + i;
            if (next > 100) {
                continue;
            }
            if (vis[next] == 0 || vis[next] > vis[now] + 1) {
                vis[next] = vis[now] + 1;
                q.push(next);
            }
        }
    }

    cout << vis[100] - 1;
}