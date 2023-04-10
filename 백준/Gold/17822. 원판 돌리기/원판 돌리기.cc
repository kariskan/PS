#include <iostream>
#include <queue>
using namespace std;

int n, m, t, x, d, k;
int circle[51][51];  // i번째에 오른쪽 기준(i, 0)으로, 시계 방향으로 작성

void rotateClockwise(int idx, int cnt) {  // 1, 3, 5, 4 -> 4, 1, 3, 5
    for (int i = 0; i < cnt; i++) {
        int last = circle[idx][m];
        for (int j = m; j >= 2; j--) {
            circle[idx][j] = circle[idx][j - 1];
        }
        circle[idx][1] = last;
    }
}

void rotateCounterClockwise(int idx, int cnt) {
    for (int i = 0; i < cnt; i++) {
        int first = circle[idx][1];
        for (int j = 1; j < m; j++) {
            circle[idx][j] = circle[idx][j + 1];
        }
        circle[idx][m] = first;
    }
}

double getAvg() {
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (circle[i][j] != 0) {
                cnt++;
                res += circle[i][j];
            }
        }
    }
    return res / (cnt * 1.0);
}

void eraseAdjecant() {
    queue<pair<int, int>> erase;

    for (int c = 1; c <= n; c++) {
        for (int i = 1; i <= m; i++) {
            for (int j = c - 1; j >= 1; j--) {  // 반지름이 작은 원 체크
                if (circle[c][i] != circle[j][i] || circle[c][i] == 0) {
                    break;
                }
                erase.push({j, i});
            }
            for (int j = c + 1; j <= n; j++) {  // 반지름이 큰 원 체크
                if (circle[c][i] != circle[j][i] || circle[c][i] == 0) {
                    break;
                }
                erase.push({j, i});
            }
            if (i != m && circle[c][i] == circle[c][i + 1] && circle[c][i] != 0) {
                erase.push({c, i});
                erase.push({c, i + 1});
            }
        }
        if (circle[c][1] == circle[c][m] && circle[c][1] != 0) {
            erase.push({c, 1});
            erase.push({c, m});
        }
    }
    if (!erase.empty()) {
        while (!erase.empty()) {
            int x = erase.front().first;
            int y = erase.front().second;
            erase.pop();

            circle[x][y] = 0;
        }
    } else {
        double avg = getAvg();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (circle[i][j] == 0) {
                    continue;
                }
                if (avg < circle[i][j]) {
                    circle[i][j]--;
                } else if (avg > circle[i][j]) {
                    circle[i][j]++;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> circle[i][j];
        }
    }

    for (int i = 0; i < t; i++) {
        cin >> x >> d >> k;
        for (int j = x; j <= n; j += x) {
            if (d == 0) {  // 시계
                rotateClockwise(j, k);
            } else {
                rotateCounterClockwise(j, k);
            }
        }
        eraseAdjecant();
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += circle[i][j];
        }
    }

    cout << ans;
}