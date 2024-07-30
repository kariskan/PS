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

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char board[10][10], cBoard[10][10];
int desX, desY;

struct coor {
    int rx;
    int ry;
    int bx;
    int by;
};

void copyBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cBoard[i][j] = board[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    coor c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                c.rx = i;
                c.ry = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'B') {
                c.bx = i;
                c.by = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'O') {
                desX = i;
                desY = j;
            }
        }
    }

    int vis[10][10][10][10] = {0,};
    queue<coor> q;

    q.push(c);
    vis[c.rx][c.ry][c.bx][c.by] = 1;

    while (!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        q.pop();

        if (board[bx][by] == 'O') {
            continue;
        }
        if (board[rx][ry] == 'O') {
            cout << vis[rx][ry][bx][by] - 1;
            return 0;
        }

        // right
        copyBoard();
        if (ry >= by) {
            int rj = ry;
            while (cBoard[rx][rj] != 'O') {
                rj++;
                if (cBoard[rx][rj] == '#') {
                    rj--;
                    break;
                }
            }
            int bj = by;
            while (cBoard[bx][bj] != 'O') {
                bj++;
                if (cBoard[bx][bj] == '#' || (bx == rx && bj == rj && board[bx][bj] != 'O')) {
                    bj--;
                    break;
                }
            }
            if (!vis[rx][rj][bx][bj]) {
                vis[rx][rj][bx][bj] = vis[rx][ry][bx][by] + 1;
                q.push(coor{rx, rj, bx, bj});
            }
        } else {
            int bj = by;
            while (cBoard[bx][bj] != 'O') {
                bj++;
                if (cBoard[bx][bj] == '#') {
                    bj--;
                    break;
                }
            }
            int rj = ry;
            while (cBoard[rx][rj] != 'O') {
                rj++;
                if (cBoard[rx][rj] == '#' || (bx == rx && bj == rj && board[bx][bj] != 'O')) {
                    rj--;
                    break;
                }
            }
            if (!vis[rx][rj][bx][bj]) {
                vis[rx][rj][bx][bj] = vis[rx][ry][bx][by] + 1;
                q.push(coor{rx, rj, bx, bj});
            }
        }
        // left
        copyBoard();
        if (ry >= by) {
            int bj = by;
            while (cBoard[bx][bj] != 'O') {
                bj--;
                if (cBoard[bx][bj] == '#') {
                    bj++;
                    break;
                }
            }
            int rj = ry;
            while (cBoard[rx][rj] != 'O') {
                rj--;
                if (cBoard[rx][rj] == '#' || (bx == rx && bj == rj && board[bx][bj] != 'O')) {
                    rj++;
                    break;
                }
            }
            if (!vis[rx][rj][bx][bj]) {
                vis[rx][rj][bx][bj] = vis[rx][ry][bx][by] + 1;
                q.push(coor{rx, rj, bx, bj});
            }
        } else {
            int rj = ry;
            while (cBoard[rx][rj] != 'O') {
                rj--;
                if (cBoard[rx][rj] == '#') {
                    rj++;
                    break;
                }
            }
            int bj = by;
            while (cBoard[bx][bj] != 'O') {
                bj--;
                if (cBoard[bx][bj] == '#' || (bx == rx && bj == rj && board[bx][bj] != 'O')) {
                    bj++;
                    break;
                }
            }
            if (!vis[rx][rj][bx][bj]) {
                vis[rx][rj][bx][bj] = vis[rx][ry][bx][by] + 1;
                q.push(coor{rx, rj, bx, bj});
            }
        }
        // up
        copyBoard();
        if (rx >= bx) {
            int bi = bx;
            while (cBoard[bi][by] != 'O') {
                bi--;
                if (cBoard[bi][by] == '#') {
                    bi++;
                    break;
                }
            }
            int ri = rx;
            while (cBoard[ri][ry] != 'O') {
                ri--;
                if (cBoard[ri][ry] == '#' || (ri == bi && ry == by && board[ri][ry] != 'O')) {
                    ri++;
                    break;
                }
            }
            if (!vis[ri][ry][bi][by]) {
                vis[ri][ry][bi][by] = vis[rx][ry][bx][by] + 1;
                q.push(coor{ri, ry, bi, by});
            }
        } else {
            int ri = rx;
            while (cBoard[ri][ry] != 'O') {
                ri--;
                if (cBoard[ri][ry] == '#') {
                    ri++;
                    break;
                }
            }
            int bi = bx;
            while (cBoard[bi][by] != 'O') {
                bi--;
                if (cBoard[bi][by] == '#' || (ri == bi && ry == by && board[ri][ry] != 'O')) {
                    bi++;
                    break;
                }
            }
            if (!vis[ri][ry][bi][by]) {
                vis[ri][ry][bi][by] = vis[rx][ry][bx][by] + 1;
                q.push(coor{ri, ry, bi, by});
            }
        }
        // down
        copyBoard();
        if (rx >= bx) {
            int ri = rx;
            while (cBoard[ri][ry] != 'O') {
                ri++;
                if (cBoard[ri][ry] == '#') {
                    ri--;
                    break;
                }
            }
            int bi = bx;
            while (cBoard[bi][by] != 'O') {
                bi++;
                if (cBoard[bi][by] == '#' || (ri == bi && ry == by && board[ri][ry] != 'O')) {
                    bi--;
                    break;
                }
            }
            if (!vis[ri][ry][bi][by]) {
                vis[ri][ry][bi][by] = vis[rx][ry][bx][by] + 1;
                q.push(coor{ri, ry, bi, by});
            }
        } else {
            int bi = bx;
            while (cBoard[bi][by] != 'O') {
                bi++;
                if (cBoard[bi][by] == '#') {
                    bi--;
                    break;
                }
            }
            int ri = rx;
            while (cBoard[ri][ry] != 'O') {
                ri++;
                if (cBoard[ri][ry] == '#' || (ri == bi && ry == by && board[ri][ry] != 'O')) {
                    ri--;
                    break;
                }
            }
            if (!vis[ri][ry][bi][by]) {
                vis[ri][ry][bi][by] = vis[rx][ry][bx][by] + 1;
                q.push(coor{ri, ry, bi, by});
            }
        }
    }

    cout << -1;
}