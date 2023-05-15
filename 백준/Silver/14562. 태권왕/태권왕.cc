#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;

        queue<pair<int, int>> q;
        int vis[301][301] = {0};

        vis[a][b] = 1;
        q.push({a, b});

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == y) {
                cout << vis[x][y] - 1 << '\n';
                break;
            }

            if (x * 2 <= 300 && y + 3 <= 300 && !vis[x * 2][y + 3]) {
                q.push({x * 2, y + 3});
                vis[x * 2][y + 3] = vis[x][y] + 1;
            }
            if (x + 1 <= 300 && !vis[x + 1][y]) {
                q.push({x + 1, y});
                vis[x + 1][y] = vis[x][y] + 1;
            }
        }
    }
}