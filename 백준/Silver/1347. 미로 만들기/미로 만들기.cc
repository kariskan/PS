#include <iostream>
using namespace std;

int ans[200][200];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int changeDir(int dir, char c) {
    if (c == 'L') {
        return (dir + 3) % 4;
    }
    return (dir + 1) % 4;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int minx = 100, miny = 100, maxx = 100, maxy = 100;
    int x = 100, y = 100, dir = 0;
    ans[x][y] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L' || s[i] == 'R') {
            dir = changeDir(dir, s[i]);
        } else {
            x += dx[dir];
            y += dy[dir];
        }
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
        ans[x][y] = 1;
    }

    for (int i = minx; i <= maxx; i++) {
        for (int j = miny; j <= maxy; j++) {
            if (ans[i][j]) {
                cout << '.';
            } else {
                cout << '#';
            }
        }
        cout << '\n';
    }
}