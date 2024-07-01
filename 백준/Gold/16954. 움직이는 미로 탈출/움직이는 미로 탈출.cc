#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

char board[9][8][8];
int vis[100][8][8];
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};

bool isRange(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                board[i][j][k] = '.';
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[0][i][j];
        }
    }
    for (int k = 1; k <= 8; k++) {
        for (int i = k; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[k][i][j] = board[k - 1][i - 1][j];
            }
        }
    }

    queue<pair<int, pair<int, int> > > q;
    q.push({0, {7, 0}});
    vis[0][7][0] = 1;

    while (!q.empty()) {
        int time = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == 0 && y == 7) {
            cout << 1;
            return 0;
        }

        for (int i = 0; i < 9; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = min(time + 1, 8);
            if (isRange(nx, ny) && board[time][nx][ny] == '.' && board[nt][nx][ny] == '.' && !vis[nt][nx][ny]) {
                q.push({nt, {nx, ny}});
                vis[nt][nx][ny] = vis[time][x][y] + 1;
            }
        }
    }
    cout << 0;
}
