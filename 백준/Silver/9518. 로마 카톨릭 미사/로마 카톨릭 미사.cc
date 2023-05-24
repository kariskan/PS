#include <cstring>
#include <iostream>
using namespace std;

int n, m;
char board[50][50];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int vis[50][50][50][50] = {0};

int getScore() {
    int res = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    board[nx][ny] == 'o' && !vis[i][j][nx][ny]) {
                    vis[i][j][nx][ny] = vis[nx][ny][i][j] = 1;
                    res++;
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int ans = getScore();
    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                int temp = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        board[nx][ny] == 'o') {
                        temp++;
                    }
                }
                ans2 = max(ans2, temp);
            }
        }
    }

    cout << ans + ans2;
}