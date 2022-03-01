#include <iostream>
#include <vector>
using namespace std;
int board[9][9];
int c[10][10], c2[10][10], c3[10][10]; //i행에 숫자 j가 있으면 1, i열에 숫자 j가 있으면 1, i번 작은 정사각형에 숫자 j가 있으면 1
int dom[10][10]; //도미노
int greed[10][10]; //그리드
int kk[10][10];
int b;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
int n;
int ansCnt = 1;

int square(int i, int j) {
    return (i / 3) * 3 + j / 3;
}

bool check(int cnt) {
    if (cnt == 36) {
        return true;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!dom[i][j] && !greed[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + x[k];
                    int ny = j + y[k];
                    if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9 && !dom[nx][ny] && !greed[nx][ny] && !kk[min(board[i][j],board[nx][ny])][max(board[i][j],board[nx][ny])]) {
                        kk[min(board[i][j], board[nx][ny])][max(board[i][j], board[nx][ny])] = 1;
                        dom[i][j] = 1;
                        dom[nx][ny] = 1;
                        if (check(cnt + 1))return true;
                        dom[i][j] = 0;
                        dom[nx][ny] = 0;
                        kk[min(board[i][j], board[nx][ny])][max(board[i][j], board[nx][ny])] = 0;
                    }
                }
                return false;
            }
        }
    }
}

void run(int z) {
    if (z == 81) {
        if (check(n)) {
            cout << "Puzzle " << ansCnt++ << "\n";
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cout << board[i][j];
                }
                cout << "\n";
            }
            b = 1;
            return;
        }
    }
    int x = z / 9, y = z % 9;
    if (board[x][y])run(z + 1);
    else {
        for (int i = 1; i <= 9; i++) {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
                c[x][i] = 1;
                c2[y][i] = 1;
                c3[square(x, y)][i] = 1;
                board[x][y] = i;
                run(z + 1);
                if (b)return;
                c[x][i] = 0;
                c2[y][i] = 0;
                c3[square(x, y)][i] = 0;
                board[x][y] = 0;
            }
        }
    }
}

int main() {
    while (1) {
        cin >> n;
        if (n == 0)return 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            string s, s1;
            cin >> a >> s >> b >> s1;
            board[s[0] - 65][s[1] - '0' - 1] = a;
            if (board[s[0] - 65][s[1] - '0' - 1] != 0) {
                c[s[0] - 65][board[s[0] - 65][s[1] - '0' - 1]] = 1;
                c2[s[1] - '0' - 1][board[s[0] - 65][s[1] - '0' - 1]] = 1;
                c3[square(s[0] - 65, s[1] - '0' - 1)][board[s[0] - 65][s[1] - '0' - 1]] = 1;
            }
            board[s1[0] - 65][s1[1] - '0' - 1] = b;
            if (board[s1[0] - 65][s1[1] - '0' - 1] != 0) {
                c[s1[0] - 65][board[s1[0] - 65][s1[1] - '0' - 1]] = 1;
                c2[s1[1] - '0' - 1][board[s1[0] - 65][s1[1] - '0' - 1]] = 1;
                c3[square(s1[0] - 65, s1[1] - '0' - 1)][board[s1[0] - 65][s1[1] - '0' - 1]] = 1;
            }
            dom[s[0] - 65][s[1] - '0' - 1] = 1;
            dom[s1[0] - 65][s1[1] - '0' - 1] = 1;
            kk[min(a, b)][max(a, b)] = 1;
        }
        for (int i = 0; i < 9; i++) {
            string s;
            cin >> s;
            board[s[0] - 65][s[1] - '0' - 1] = i + 1;
            if (board[s[0] - 65][s[1] - '0' - 1] != 0) {
                c[s[0] - 65][board[s[0] - 65][s[1] - '0' - 1]] = 1;
                c2[s[1] - '0' - 1][board[s[0] - 65][s[1] - '0' - 1]] = 1;
                c3[square(s[0] - 65, s[1] - '0' - 1)][board[s[0] - 65][s[1] - '0' - 1]] = 1;
            }
            greed[s[0] - 65][s[1] - '0' - 1] = 1;
        }
        run(0);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = c2[i][j] = c3[i][j] = dom[i][j] = greed[i][j] = kk[i][j] = 0;
                if (i != 9 && j != 9)board[i][j] = 0;
            }
        }
        b = 0;
    }
}