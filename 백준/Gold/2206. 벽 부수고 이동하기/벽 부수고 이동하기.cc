#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
string board[1001];
int visit[1001][1001][2];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    queue<tuple<int, int, int>> q;
    visit[0][0][0] = 1;
    q.push({ 0,0,0 });
    while (!q.empty()) {
        int a, b, c;
        tie(a, b, c) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = a + x[i];
            int ny = b + y[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (board[nx][ny] == '0' && visit[nx][ny][c] == 0) {
                    visit[nx][ny][c] = visit[a][b][c] + 1;
                    q.push({ nx,ny,c });
                }
                if (c == 0 && board[nx][ny] == '1' && visit[nx][ny][1] == 0) {
                    visit[nx][ny][1] = visit[a][b][0] + 1;
                    q.push({ nx,ny,1 });
                }
            }
        }
    }
    if (n == 1 && m == 1)cout << 1;
    else {
        if (visit[n - 1][m - 1][0] == 0 && visit[n - 1][m - 1][1] == 0)cout << -1;
        else {
            if (visit[n - 1][m - 1][0] == 0)cout << visit[n - 1][m - 1][1];
            else if (visit[n - 1][m - 1][1] == 0)cout << visit[n - 1][m - 1][0];
            else cout << min(visit[n - 1][m - 1][0], visit[n - 1][m - 1][1]);
        }
    }
}