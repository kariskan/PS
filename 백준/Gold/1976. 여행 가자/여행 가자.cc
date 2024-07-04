#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

int board[201][201];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
        board[i][i] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }
                if (board[i][k] && board[k][j]) {
                    board[i][j] = 1;
                }
            }
        }
    }
    int start;
    cin >> start;
    for (int i = 0; i < m - 1; i++) {
        int next;
        cin >> next;
        if (board[start][next] == 0) {
            cout << "NO";
            return 0;
        }
        start = next;
    }
    cout << "YES";
}
