#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <mutex>
using namespace std;

int board[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        board[i][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][k] && board[k][j]) {
                    board[i][j] = 1;
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (board[i][j] && board[j][i]) {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for (auto &i: ans) {
        cout << i << '\n';
    }
}