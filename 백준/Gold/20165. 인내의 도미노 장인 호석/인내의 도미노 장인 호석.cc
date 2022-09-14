#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, r, map[101][101], inp[101][101];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

int go(int i, int j, int k) {
    if (!map[i][j]) return 0;
    queue<tuple<int, int, int>> q;
    q.push({ i,j,map[i][j] });

    int cnt = 1;
    map[i][j] = 0;

    while (!q.empty()) {
        int a, b, c;
        tie(a, b, c) = q.front();
        q.pop();

        for (int l = 1; l < c; l++) {
            int nx = a + l * x[k];
            int ny = b + l * y[k];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny]) {
                q.push({ nx,ny,map[nx][ny] });
                map[nx][ny] = 0;
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            inp[i][j] = map[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < r * 2; i++) {
        int x, y;
        char d;
        if (i % 2 == 0) { //공
            cin >> x >> y >> d;
            if (d == 'E') ans += go(x, y, 0);
            else if (d == 'W') ans += go(x, y, 1);
            else if (d == 'S') ans += go(x, y, 2);
            else ans += go(x, y, 3);
        }
        else { //수
            cin >> x >> y;
            map[x][y] = inp[x][y];
        }
    }

    cout << ans << '\n';

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j]) cout << "S ";
            else cout << "F ";
        }
        cout << '\n';
    }
}