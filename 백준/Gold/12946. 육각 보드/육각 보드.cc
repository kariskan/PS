#include <iostream>
using namespace std;
int n;
char board[51][51];
int visit[51][51];
int x[6] = { 0,0,1,1,-1,-1 };
int y[6] = { 1,-1,0,-1,1,0 };
int ans;
void run(int i, int j, int c) {
    visit[i][j] = c;
    ans = max(ans, 1);
    for (int k = 0; k < 6; k++) {
        int nx = x[k] + i;
        int ny = y[k] + j;
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 'X') {
            if (!visit[nx][ny]) {
                run(nx, ny, 3 - c);
            }
            ans = max(ans, 2);
            if (visit[nx][ny] == c) {
                ans = max(ans, 3);
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && board[i][j] == 'X') {
                run(i, j, 1);
            }
        }
    }
    cout << ans;
}