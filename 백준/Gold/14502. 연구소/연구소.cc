#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int board[8][8] = { 0, };
    int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
    int n, m;
    queue<pair<int, int>> q;
    cin >> n >> m;
    int vSize = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2 || board[i][j] == 1)vSize++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n * m - 2; i++) {
        for (int j = i + 1; j < n * m - 1; j++) {
            for (int k = j + 1; k < n * m; k++) {
                if (board[i / m][i % m] == 2 || board[j / m][j % m] == 2 || board[k / m][k % m] == 2|| 
                    board[i / m][i % m] == 1 || board[j / m][j % m] == 1 || board[k / m][k % m] == 1)continue;
                board[i / m][i % m] = 1;
                board[j / m][j % m] = 1;
                board[k / m][k % m] = 1;
                int tSize = vSize;
                int visit[8][8] = { 0, };
                for (int i1 = 0; i1 < n; i1++) {
                    for (int j1 = 0; j1 < m; j1++) {
                        if (board[i1][j1] != 2) continue;
                        q.push({ i1,j1 });
                        while (!q.empty()) {
                            int a = q.front().first;
                            int b = q.front().second;
                            q.pop();
                            for (int l = 0; l < 4; l++) {
                                int nx = a + x[l];
                                int ny = b + y[l];
                                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                                    if (board[nx][ny] == 0 && !visit[nx][ny]) {
                                        visit[nx][ny] = 1;
                                        q.push({ nx,ny });
                                        tSize++;
                                    }
                                }
                            }
                        }
                    }
                }
                int asdf = 0;
                board[i / m][i % m] = 0;
                board[j / m][j % m] = 0;
                board[k / m][k % m] = 0;
                ans = max(ans, n * m - tSize - 3);
            }
        }
    }
    cout << ans;
}