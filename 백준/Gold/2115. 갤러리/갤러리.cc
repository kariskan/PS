#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>

using namespace std;

char board[1000][1000];
int vis[1000][1000][4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (board[i][j] == '.' && board[i][j + 1] == '.' && !vis[i][j][0] && !vis[i][j + 1][0] &&
                board[i - 1][j] == 'X' && board[i - 1][j + 1] == 'X') {
                answer++;
                vis[i][j][0] = vis[i][j + 1][0] = 1;
            }
            if (board[i][j] == '.' && board[i][j + 1] == '.' && !vis[i][j][2] && !vis[i][j + 1][2] &&
                board[i + 1][j] == 'X' && board[i + 1][j + 1] == 'X') {
                answer++;
                vis[i][j][2] = vis[i][j + 1][2] = 1;
            }
            if (board[i][j] == '.' && board[i + 1][j] == '.' && !vis[i][j][3] && !vis[i + 1][j][3] &&
                board[i][j - 1] == 'X' && board[i + 1][j - 1] == 'X') {
                answer++;
                vis[i][j][3] = vis[i + 1][j][3] = 1;
            }
            if (board[i][j] == '.' && board[i + 1][j] == '.' && !vis[i][j][1] && !vis[i + 1][j][1] &&
                board[i][j + 1] == 'X' && board[i + 1][j + 1] == 'X') {
                answer++;
                vis[i][j][1] = vis[i + 1][j][1] = 1;
            }
        }
    }
    cout << answer;
}