#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <mutex>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int board[500][500];
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            continue;
        }
        for (int j = 0; j < a; j++) {
            board[j][i] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == 0) {
                bool flag = true;
                int idx = j - 1;
                while (idx >= 0 && board[i][idx] == 0) {
                    idx--;
                }
                if (idx == -1) {
                    flag = false;
                }
                idx = j + 1;
                while (idx < w && board[i][idx] == 0) {
                    idx++;
                }
                if (idx == w) {
                    flag = false;
                }

                if (flag) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
}
