#include <iostream>
#include <queue>
using namespace std;

int r1, c1, r2, c2, vis[10][9];
int dx[8][3] = {{0, -1, -1}, {0, 1, 1},   {1, 1, 1},    {1, 1, 1},
                {0, 1, 1},   {0, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
int dy[8][3] = {{1, 1, 1},    {1, 1, 1},    {0, 1, 1},   {0, -1, -1},
                {-1, -1, -1}, {-1, -1, -1}, {0, -1, -1}, {0, 1, 1}};
                
bool range(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 9;
}

int main() {
    cin >> r1 >> c1 >> r2 >> c2;
    queue<pair<int, int>> q;
    q.push({r1, c1});
    vis[r1][c1] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == r2 && y == c2) {
            cout << vis[x][y] - 1;
            return 0;
        }

        for (int i = 0; i < 8; i++) {
            bool flag = true;
            int tx = x, ty = y;
            queue<pair<int, int>> temp;
            for (int j = 0; j < 3; j++) {
                int nx = tx + dx[i][j];
                int ny = ty + dy[i][j];
                if (!(range(nx, ny) && !(j < 2 && nx == r2 && ny == c2))) {
                    flag = false;
                    break;
                }
                tx = nx, ty = ny;
            }
            if (flag) {
                int nx = dx[i][0] + dx[i][1] + dx[i][2];
                int ny = dy[i][0] + dy[i][1] + dy[i][2];
                q.push({x + nx, y + ny});
                vis[x + nx][y + ny] = vis[x][y] + 1;
            }
        }
    }
    cout << -1;
}