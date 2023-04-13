#include <deque>
#include <iostream>
using namespace std;

int n, k, board[13][13], direction[11];
pair<int, int> location[11];
deque<int> dq[13][13];  // 말 번호, front에 있을수록 밑으로 간다.

pair<int, int> nextLocation(int dir, pair<int, int> now) {
    if (dir == 1) {
        return {now.first, now.second + 1};
    } else if (dir == 2) {
        return {now.first, now.second - 1};
    } else if (dir == 3) {
        return {now.first - 1, now.second};
    }
    return {now.first + 1, now.second};
}

int getReverseDir(int dir) {
    if (dir == 1) return 2;
    if (dir == 2) return 1;
    if (dir == 3) return 4;
    return 3;
}

bool oor(pair<int, int> p) {  // out of range
    return !(p.first > 0 && p.first <= n && p.second > 0 && p.second <= n);
}

void move(int nowX, int nowY, pair<int, int> next, int idx) {
    deque<int> temp;
    while (1) {
        temp.push_front(dq[nowX][nowY].back());  // 현재 위치의 위에서 부터 i번 말이 나올때까지 빼낸다.
        dq[nowX][nowY].pop_back();
        if (temp.front() == idx) {
            break;
        }
    }
    while (!temp.empty()) {
        int now;
        if (board[next.first][next.second] == 1) {  // 빨간색 칸으로 이동하려는 경우
            now = temp.back();                      // 뒤에서 부터 꺼낸다.
            temp.pop_back();
        } else {                 // 흰색
            now = temp.front();  // 앞에서 부터 꺼낸다.
            temp.pop_front();
        }
        location[now] = next;
        dq[next.first][next.second].push_back(now);  // 위로 쌓는다.
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        location[i] = {x, y};
        direction[i] = dir;
        dq[x][y].push_back(i);
    }

    for (int t = 1; t <= 1000; t++) {
        for (int i = 1; i <= k; i++) {  // 1번 말부터 차례대로 이동
            int nowX = location[i].first;
            int nowY = location[i].second;
            pair<int, int> next = nextLocation(direction[i], {nowX, nowY});  // 다음 위치를 구하고

            if (oor(next) || board[next.first][next.second] == 2) {  // 파란색이거나 밖으로 나가는 경우
                direction[i] = getReverseDir(direction[i]);          // 방향을 바꾼다.
                next = nextLocation(direction[i], {nowX, nowY});
                if (board[next.first][next.second] == 2 || oor(next)) {  // 방향을 바꾼 칸도 밖이거나 파란색이면 이동하지 않는다.
                    continue;
                }
            }
            move(nowX, nowY, next, i);
            if (dq[next.first][next.second].size() >= 4) {
                cout << t;
                return 0;
            }
        }
    }

    cout << -1;
}