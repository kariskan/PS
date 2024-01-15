#include <iostream>
#include <vector>
using namespace std;
int r, c, t;
int map[50][50];
int cfx = -1, cfy = -1, csx = -1, csy = -1;
int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };
void diffusion() {
    int temp[50][50] = { 0, };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[i][j] = map[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (temp[i][j] < 5) {
                continue;
            }
            else {
                if (temp[i][j] < 5)continue;
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + x[k];
                    int ny = j + y[k];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && temp[nx][ny] != -1) {
                        map[nx][ny] += temp[i][j] / 5;
                        sum += temp[i][j] / 5;
                    }
                }
                map[i][j] -= sum;
            }
        }
    }
}
void rotate() {
    int I = 0;
    int nx = csx, ny = csy;
    int t1 = map[nx][ny], t2 = map[nx + x[0]][ny + y[0]];
    while (1) {
        nx += x[I];
        ny += y[I];
        if (nx == csx && ny == csy) {
            break;
        }
        if (!(nx >= 0 && nx < r && ny >= 0 && ny < c)) {
            nx -= x[I];
            ny -= y[I];
            I++;
            nx += x[I];
            ny += y[I];
        }
        t2 = map[nx][ny];
        if (t1 == -1) map[nx][ny] = 0;
        else map[nx][ny] = t1;
        t1 = t2;
    }


    I = 0;
    nx = cfx, ny = cfy;
    t1 = map[nx][ny], t2 = map[nx - x[0]][ny + y[0]];
    while (1) {
        nx -= x[I];
        ny += y[I];
        if (nx == cfx && ny == cfy) {
            break;
        }
        if (!(nx >= 0 && nx < r && ny >= 0 && ny < c)) {
            nx += x[I];
            ny -= y[I];
            I++;
            nx -= x[I];
            ny += y[I];
        }
        t2 = map[nx][ny];
        if (t1 == -1) map[nx][ny] = 0;
        else map[nx][ny] = t1;
        t1 = t2;
    }
}
int main() {
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1) {
                if (cfx == -1) {
                    cfx = i;
                    cfy = j;
                }
                else {
                    csx = i;
                    csy = j;
                }
            }
        }
    }
    while (t--) {
        diffusion();
        rotate();
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == -1)continue;
            ans += map[i][j];
        }
    }
    cout << ans;
}