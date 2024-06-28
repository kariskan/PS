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
#include <sstream>
#include <map>

using namespace std;

int n, c, e, cBoard[100][100], eBoard[100][100];

void fill(bool flag) {
    int count = 0;
    for (int s = 0; s <= 2 * (n - 1); s++) {
        for (int i = 0; i <= s; i++) {
            if (i < n && s - i < n) {
                if (flag) {
                    cBoard[i][s - i] = 1;
                    count++;
                } else {
                    eBoard[i][s - i] = 1;
                    count++;
                }
            }
            if (flag) {
                if (count == c) {
                    return;
                }
            } else {
                if (count == e) {
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c >> e;

    vector<int> v;
    for (int i = 1; i < n; i++) {
        v.push_back(i);
    }
    v.push_back(n - 1);
    for (int i = n - 1; i >= 1; i--) {
        v.push_back(i);
    }

    int maxNumCnt = 0;
    int num = 2;
    vector<int> around;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i]; j++) {
            around.push_back(num);
        }
        if (maxNumCnt == 0) {
            num++;
            if (num == n + 1) {
                num--;
                maxNumCnt++;
            }
        } else {
            num--;
        }
    }

    for (int t = 0; t < around.size(); t++) {
        if (t + 1 >= c && n * n - (t + 1) - around[t] >= e) {
            cout << 1 << '\n';

            fill(true);
            fill(false);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (cBoard[i][j]) {
                        cout << 1;
                    } else if (eBoard[n - i - 1][n - j - 1]) {
                        cout << 2;
                    } else {
                        cout << 0;
                    }
                }
                cout << '\n';
            }
            return 0;
        }
    }

    cout << -1;
}