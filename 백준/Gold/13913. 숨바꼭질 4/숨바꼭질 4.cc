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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    int vis[200001] = {0,}, pre[200001];

    q.push(n);
    vis[n] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == m) {
            cout << vis[x] - 1 << '\n';
            vector<int> ans;
            while (x != n) {
                ans.push_back(x);
                x = pre[x];
            }
            cout << n << ' ';
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i] << ' ';
            }
            return 0;
        }

        if (x - 1 >= 0 && !vis[x - 1]) {
            vis[x - 1] = vis[x] + 1;
            pre[x - 1] = x;
            q.push(x - 1);
        }
        if (x + 1 <= 200000 && !vis[x + 1]) {
            vis[x + 1] = vis[x] + 1;
            pre[x + 1] = x;
            q.push(x + 1);
        }
        if (x * 2 <= 200000 && !vis[x * 2]) {
            vis[x * 2] = vis[x] + 1;
            pre[x * 2] = x;
            q.push(x * 2);
        }
    }
}
