#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int l, n;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, -1, 1, 0, 0};
long long rotateTime[1000];            // i번째 회전은 i초에 일어난다.
char rotateDir[1000];                  // i번째 회전에서 바꿀 방향
vector<pair<long long, long long>> v;  // x, y history

int changeDir(int dir, char r) {  // 왼 오 위 아
    if (dir == 1) {
        if (r == 'L') {
            return 4;
        }
        return 3;
    }
    if (dir == 2) {
        if (r == 'L') {
            return 3;
        }
        return 4;
    }
    if (dir == 3) {
        if (r == 'L') {
            return 1;
        }
        return 2;
    }
    if (r == 'L') {
        return 2;
    }
    return 1;
}

int main() {
    cin >> l >> n;
    for (int i = 1; i <= n; i++) {
        cin >> rotateTime[i - 1] >> rotateDir[i - 1];
        if (i != 1) {
            rotateTime[i - 1] = rotateTime[i - 2] + rotateTime[i - 1];
        }
    }

    int dir = 2, x = l, y = l;
    long long nowTime = 0;
    v.push_back({x, y});

    for (int i = 0; i <= n; i++) {
        long long tx = x, ty = y;
        if (i == n) {
            x += dx[dir] * 1000000000;
            y += dy[dir] * 1000000000;
        } else {
            x += dx[dir] * (rotateTime[i] - nowTime);
            y += dy[dir] * (rotateTime[i] - nowTime);
            dir = changeDir(dir, rotateDir[i]);
        }

        pair<long long, long long> start = v[v.size() - 1];  // 왼쪽 위에 오게
        pair<long long, long long> end = {x, y};             // 오른쪽 아래에 오게

        long long ans = LLONG_MAX;

        for (int j = v.size() - 3; j >= 0; j--) {
            pair<long long, long long> left = v[j];
            pair<long long, long long> right = v[j + 1];
            if (left.first > right.first || left.second > right.second) {
                swap(left, right);
            }

            if (start.first == end.first) {       // start-end가 가로
                if (left.first == right.first) {  // left-right가 가로
                    if (start.first == left.first && end.second >= left.second && start.second <= left.second) {
                        ans = min(ans, nowTime + abs(left.second - start.second));
                    }
                } else if (left.second == right.second) {  // left-right가 세로
                    if (start.first >= left.first && start.first <= right.first && left.second >= min(start.second, end.second) && left.second <= max(start.second, end.second)) {
                        ans = min(ans, nowTime + abs(left.second - start.second));
                    }
                }
            } else {                              // start-end가 세로
                if (left.first == right.first) {  // left-right가 가로
                    if (min(start.first, end.first) <= left.first && max(start.first, end.first) >= right.first && left.second <= start.second && right.second >= end.second) {
                        ans = min(ans, nowTime + abs(left.first - start.first));
                    }
                } else {  // left-right가 세로
                    if (start.second == left.second && end.first >= left.first && start.first <= left.first) {
                        ans = min(ans, nowTime + abs(left.first - start.first));
                    }
                }
            }
        }

        if (!(x >= 0 && y >= 0 && x < 2 * l + 1 && y < 2 * l + 1)) {
            if (x < 0) {
                ans = min(ans, nowTime + tx + 1);
            } else if (y < 0) {
                ans = min(ans, nowTime + ty + 1);
            } else if (x >= 2 * l + 1) {
                ans = min(ans, nowTime + 2 * l + 1 - tx);
            } else {
                ans = min(ans, nowTime + 2 * l + 1 - ty);
            }
        }

        if (ans != LLONG_MAX) {
            cout << ans;
            return 0;
        }

        if (i != n) {
            nowTime = rotateTime[i];
        }
        v.push_back({x, y});
    }
}