#include <iostream>
using namespace std;

int map[3][3];
int xcnt, ocnt;

bool isGameSet(int turn) { //해당 turn의 플레이어가 이겼는지 체크
    for (int i = 0; i < 3; i++) {
        if (map[i][0] == turn && (map[i][0] == map[i][1] && map[i][1] == map[i][2])) {
            return true;
        }
        if (map[0][i] == turn && (map[0][i] == map[1][i] && map[1][i] == map[2][i])) {
            return true;
        }
    }

    if (map[0][0] == turn && map[0][0] == map[1][1] && map[1][1] == map[2][2]) {
        return true;
    }
    if (map[0][2] == turn && map[0][2] == map[1][1] && map[1][1] == map[2][0]) {
        return true;
    }

    return false;
}

int go(int turn) {
    
    // 상대편이 현재 이겼다면 볼 필요 없다.
    if (isGameSet(3 - turn)) return -1;

    int mi = 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] == 0) {
                map[i][j] = turn;
                mi = min(mi, go(3 - turn));
                map[i][j] = 0;
            }
        }
    }

    if (mi == 2 || mi == 0) {
        return 0;
    }

    return -mi;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                xcnt++;
            } else if (map[i][j] == 2) {
                ocnt++;
            }
        }
    }

    int turn = xcnt > ocnt ? 2 : 1;

    int res = go(turn);

    if (res == 0)
        cout << "D";

    else if (res == 1)
        cout << "W";

    else
        cout << "L";
}