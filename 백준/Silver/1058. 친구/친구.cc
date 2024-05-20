#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

char board[51][51];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            if (board[i][j] == 'Y') {
                cnt++;
            } else {
                bool flag = false;
                for (int k = 1; k <= n; k++) {
                    if (board[i][k] == 'Y' && board[j][k] == 'Y') {
                        flag = true;
                    }
                }
                if (flag) {
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
    }
    cout << answer;
}