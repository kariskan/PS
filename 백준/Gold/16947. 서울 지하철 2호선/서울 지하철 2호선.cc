#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <cstring>
#include <stack>
using namespace std;

vector<vector<int> > board;
int n, vis[3001], cycle[3001];

bool r;
int t;

void go(int node, int pre) {
    vis[node] = 1;
    for (auto &i: board[node]) {
        if (i != pre) {
            if (vis[i]) {
                cycle[node] = 1;
                r = true;
                t = i;
                return;
            }
            go(i, node);
            if (r) {
                cycle[node] = 1;
                if (node == t) {
                    r = false;
                }
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    go(1, 0);

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        queue<int> q;

        q.push(i);
        vis[i] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (cycle[node]) {
                cout << vis[node] - 1 << ' ';
                break;
            }

            for (auto&j:board[node]) {
                if (!vis[j]) {
                    vis[j] = vis[node] + 1;
                    q.push(j);
                }
            }
        }
    }
}
