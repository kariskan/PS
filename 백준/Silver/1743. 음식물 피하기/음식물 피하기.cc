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

int board[100][100], vis[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        board[a - 1][b - 1] = 1;
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && !vis[i][j]) {
                int cnt = 0;
                queue<pair<int, int>> q;

                q.push({i, j});
                vis[i][j] = 1;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    cnt++;

                    for (int l = 0; l < 4; l++) {
                        int nx = x + dx[l];
                        int ny = y + dy[l];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && board[nx][ny] == 1) {
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
                answer = max(answer, cnt);
            }
        }
    }
    cout << answer;
}