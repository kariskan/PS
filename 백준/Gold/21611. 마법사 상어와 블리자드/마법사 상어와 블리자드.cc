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
using namespace std;

int map[50][50], n, m;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };
int ans = 0;

// 파괴
void destroy(int d, int s) {
    int x = (n + 1) / 2, y = (n + 1) / 2;  // 정 중앙으로부터
    while (s--) {                          // 해당 방향에 거리만큼 삭제
        x += dx[d];
        y += dy[d];
        map[x][y] = 0;
    }
}

// 방향 바꾸는 함수
// 위 -> 왼, 아래 -> 오, 왼 -> 아래, 오 -> 위
int changeDir(int dir) {
    if (dir == 1) return 3;
    if (dir == 2) return 4;
    if (dir == 3) return 2;
    return 1;
}

// 이동
void move() {
    vector<int> v;

    int x = (n + 1) / 2, y = (n + 1) / 2, dis = 1, cnt = 0, dir = 1;
    while (1) {
        // 끝지점에 왔으면 break
        if (x == 1 && y == 1) {
            break;
        }

        // 방향 바꾸고
        dir = changeDir(dir);
        // 현재 이동 횟수 만큼
        for (int i = 0; i < dis; i++) {
            x += dx[dir];
            y += dy[dir];
            // 구슬이 존재한다면
            if (map[x][y]) {
                v.push_back(map[x][y]);
            }
        }

        // 이동 횟수
        cnt++;
        if (cnt == 2 && dis != n - 1) {
            dis++;
            cnt = 0;
        }
    }
    memset(map, 0, sizeof(map));
    x = (n + 1) / 2, y = (n + 1) / 2, dis = 1, cnt = 0, dir = 1;

    int idx = 0;
    int siz = v.size();

    // 존재하는 구슬의 수 만큼
    while (siz--) {
        if ((x == 1 && y == 1) || idx == v.size()) {
            break;
        }
        dir = changeDir(dir);
        for (int i = 0; i < dis; i++) {
            x += dx[dir];
            y += dy[dir];
            map[x][y] = v[idx++];
            if (idx == v.size()) {
                break;
            }
        }
        cnt++;
        if (cnt == 2 && dis != n - 1) {
            dis++;
            cnt = 0;
        }
    }
}

void boom() {
    vector<pair<int, int>> v;
    vector<pair<int, int>> temp;

    // 파괴가 일어나지 않을 때까지
    while (1) {
        int x = (n + 1) / 2, y = (n + 1) / 2, dis = 1, cnt = 0, dir = 1, last = 0, lastCnt = 0;
        bool flag = false;
        while (1) {
            if (x == 1 && y == 1) {
                break;
            }
            dir = changeDir(dir);
            for (int i = 0; i < dis; i++) {
                x += dx[dir];
                y += dy[dir];
                // 이전과 같은 구슬이라면
                if (map[x][y] == 0) {
                    continue;
                }
                if (last == map[x][y]) {
                    lastCnt++;
                    temp.push_back({ x, y });
                }
                else {                 // 이전과 다른 구슬이라면
                    if (lastCnt >= 4) {  // 연속된 구슬이 4개 이상이라면
                        while (!temp.empty()) {
                            v.push_back(temp.back());
                            ans += map[temp.back().first][temp.back().second];
                            temp.pop_back();
                        }
                        flag = true;
                    }
                    temp.clear();
                    last = map[x][y];
                    lastCnt = 1;
                    temp.push_back({ x, y });
                }
            }
            cnt++;
            if (cnt == 2 && dis != n - 1) {
                dis++;
                cnt = 0;
            }
        }
        if (lastCnt >= 4) {
            while (!temp.empty()) {
                v.push_back(temp.back());
                ans += map[temp.back().first][temp.back().second];
                temp.pop_back();
            }
            flag = true;
        }
        while (!v.empty()) {
            map[v.back().first][v.back().second] = 0;
            v.pop_back();
        }

        move();
        if (!flag) {
            break;
        }
    }
}

void change() {
    vector<pair<int, int>> v;
    vector<pair<int, int>> temp;
    int x = (n + 1) / 2, y = (n + 1) / 2, dis = 1, cnt = 0, dir = 1, last = 0, lastCnt = 0;
    while (1) {
        if (x == 1 && y == 1) {
            break;
        }
        dir = changeDir(dir);
        for (int i = 0; i < dis; i++) {
            x += dx[dir];
            y += dy[dir];
            if (map[x][y] == 0) {
                continue;
            }
            if (last == map[x][y]) {
                lastCnt++;
            }
            else {
                v.push_back({ last, lastCnt });
                last = map[x][y];
                lastCnt = 1;
            }
        }

        cnt++;
        if (cnt == 2 && dis != n - 1) {
            dis++;
            cnt = 0;
        }
    }
    v.push_back({ last, lastCnt });

    memset(map, 0, sizeof(map));

    x = (n + 1) / 2, y = (n + 1) / 2, dis = 1, cnt = 0, dir = 1;
    int t = 0, idx = 1;
    while (1) {
        if ((x == 1 && y == 1) || idx == v.size()) {
            break;
        }
        dir = changeDir(dir);
        for (int i = 0; i < dis; i++) {
            x += dx[dir];
            y += dy[dir];
            if (t == 0) {
                map[x][y] = v[idx].second;
                t = 1;
            }
            else {
                map[x][y] = v[idx].first;
                t = 0;
                idx++;
                if (idx == v.size()) {
                    break;
                }
            }
        }

        cnt++;
        if (cnt == 2 && dis != n - 1) {
            dis++;
            cnt = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        destroy(d, s);
        move();
        boom();
        change();
    }

    cout << ans;
}