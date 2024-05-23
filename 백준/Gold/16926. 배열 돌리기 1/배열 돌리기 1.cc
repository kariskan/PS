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
#include <cstring>

using namespace std;

int a[300][300], n, m, k;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void rotate() {
    for (int skin = 0; skin < min(n, m) / 2; skin++) {
        int x = skin, y = skin;
        int first = a[x][y];
        for (int i = 0; i < 4; i++) {
            int len = (i % 2 == 0 ? m - skin * 2 - 1 : n - skin * 2 - 1);
            for (int j = 0; j < len; j++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (i == 3 && j == len - 1) {
                    a[x][y] = first;
                } else {
                    a[x][y] = a[nx][ny];
                }
                x = nx;
                y = ny;
            }
        }
    }
}

int main() {

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (k--) {
        rotate();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}