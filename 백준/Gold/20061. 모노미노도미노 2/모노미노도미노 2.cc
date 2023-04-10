#include <iostream>
#include <vector>
using namespace std;

int ans, cnt;
int map[10][10];

void blue(vector<pair<int, int>> v) {  //(x, y)에 있는 블록이 파란색 보드로 이동
    int dis = 0;
    while (1) {
        bool flag = false;
        for (int i = 0; i < v.size(); i++) {
            if (map[v[i].first][v[i].second + dis + 1] != 0 || v[i].second + dis >= 9) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
        dis++;
    }
    for (int i = 0; i < v.size(); i++) {
        map[v[i].first][v[i].second + dis] = 1;
    }
}

void green(vector<pair<int, int>> v) {  //(x, y)에 있는 블록이 초록색 보드로 이동
    int dis = 0;
    while (1) {
        bool flag = false;
        for (int i = 0; i < v.size(); i++) {
            if (map[v[i].first + dis + 1][v[i].second] != 0 || v[i].first + dis >= 9) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
        dis++;
    }
    for (int i = 0; i < v.size(); i++) {
        map[v[i].first + dis][v[i].second] = 1;
    }
}

void blueEraseAndMove() {
    for (int j = 4; j < 10; j++) {
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            if (map[i][j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
            for (int i = 0; i < 4; i++) {
                map[i][j] = 0;
            }
            for (int k = j; k >= 5; k--) {
                for (int i = 0; i < 4; i++) {
                    map[i][k] = map[i][k - 1];
                }
            }
            j--;
        }
    }
}

void blueSpecial() {
    int dis = 0;
    for (int j = 4; j <= 5; j++) {
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            if (map[i][j] != 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            dis++;
        }
    }
    for (int j = 9; j >= 6; j--) {
        for (int i = 0; i < 4; i++) {
            map[i][j] = map[i][j - dis];
        }
    }
    for (int j = 4; j <= 5; j++) {
        for (int i = 0; i < 4; i++) {
            map[i][j] = 0;
        }
    }
}

void greenSpecial() {
    int dis = 0;
    for (int i = 4; i <= 5; i++) {
        bool flag = false;
        for (int j = 0; j < 4; j++) {
            if (map[i][j] != 0) {
                flag = true;
            }
        }
        if (flag) {
            dis++;
        }
    }
    for (int i = 9; i >= 6; i--) {
        for (int j = 0; j < 4; j++) {
            map[i][j] = map[i - dis][j];
        }
    }
    for (int i = 4; i <= 5; i++) {
        for (int j = 0; j < 4; j++) {
            map[i][j] = 0;
        }
    }
}

void greeneraseAndMove() {
    for (int i = 4; i < 10; i++) {
        bool flag = true;
        for (int j = 0; j < 4; j++) {
            if (map[i][j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
            for (int j = 0; j < 4; j++) {
                map[i][j] = 0;
            }
            for (int k = i; k >= 5; k--) {
                for (int j = 0; j < 4; j++) {
                    map[k][j] = map[k - 1][j];
                }
            }
            i--;
        }
    }
}

void q1(int x, int y) {
    blue({{x, y}});
    green({{x, y}});
}

void q2(int x, int y) {
    blue({{x, y}, {x, y + 1}});
    green({{x, y}, {x, y + 1}});
}

void q3(int x, int y) {
    blue({{x, y}, {x + 1, y}});
    green({{x, y}, {x + 1, y}});
}

int main() {
    int n;
    cin >> n;
    int t, x, y;
    for (int i = 0; i < n; i++) {
        cin >> t >> x >> y;
        if (t == 1) {
            q1(x, y);
        } else if (t == 2) {
            q2(x, y);
        } else {
            q3(x, y);
        }
        blueEraseAndMove();
        greeneraseAndMove();
        blueSpecial();
        greenSpecial();
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j]) {
                cnt++;
            }
        }
    }

    cout << ans << '\n' << cnt;
}