#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int m, s;
int map[5][5][9];  // (i,j)에 방향이 k인 물고기
pair<int, int> shark;
int smell[5][5];
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int sx[5] = {0, -1, 0, 1, 0};
int sy[5] = {0, 0, -1, 0, 1};

bool compare(pair<int, string>& p1, pair<int, string>& p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

int getNextDir(int dir) { return dir - 1 == 0 ? 8 : dir - 1; }

bool isShark(int nx, int ny) { return shark.first == nx && shark.second == ny; }

bool isSmell(int nx, int ny) { return smell[nx][ny] > 0; }

bool isOutOfRange(int nx, int ny) { return !(nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4); }

int getSharkMove(string move, int x, int y) {
    int nx = x, ny = y;
    int vis[5][5] = {
        0,
    };
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        nx += sx[move[i] - '0'];
        ny += sy[move[i] - '0'];
        if (!isOutOfRange(nx, ny)) {
            if (!vis[nx][ny]) {
                vis[nx][ny] = 1;
                for (int j = 1; j <= 8; j++) {
                    cnt += map[nx][ny][j];
                }
            }
        } else {
            return -1;
        }
    }
    return cnt;
}

int main() {
    cin >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b][c]++;
    }
    cin >> shark.first >> shark.second;

    while (s--) {
        // 복사본 생성
        int duplica[5][5][9];
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                for (int k = 1; k <= 8; k++) {
                    duplica[i][j][k] = map[i][j][k];
                }
            }
        }

        // 물고기 이동
        int tempMap[5][5][9] = {
            0,
        };
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                for (int k = 1; k <= 8; k++) {
                    if (map[i][j][k] == 0) {  // 물고기 없으면
                        continue;
                    }
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    int tempDir = k;
                    int cnt = 0;
                    while (cnt < 8) {
                        if (!(isShark(nx, ny) || isSmell(nx, ny) || isOutOfRange(nx, ny))) {
                            break;
                        }
                        tempDir = getNextDir(tempDir);
                        nx = i + dx[tempDir];
                        ny = j + dy[tempDir];
                        cnt++;
                    }
                    if (cnt < 8) {
                        tempMap[nx][ny][tempDir] += map[i][j][k];
                    } else {
                        tempMap[i][j][k] += map[i][j][k];
                    }
                }
            }
        }
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                for (int k = 1; k <= 8; k++) {
                    map[i][j][k] = tempMap[i][j][k];
                }
            }
        }

        vector<pair<int, string>> sharkMove;
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                for (int k = 1; k <= 4; k++) {
                    string move = "";
                    move.push_back(i + '0');
                    move.push_back(j + '0');
                    move.push_back(k + '0');
                    int erasedFish = getSharkMove(move, shark.first, shark.second);
                    sharkMove.push_back({erasedFish, move});
                }
            }
        }
        sort(sharkMove.begin(), sharkMove.end(), compare);
        string move = sharkMove[0].second;
        for (int i = 0; i < 3; i++) {
            shark.first += sx[move[i] - '0'];
            shark.second += sy[move[i] - '0'];
            for (int j = 1; j <= 8; j++) {
                if (map[shark.first][shark.second][j]) {  // 상어가 가는 곳에 물고기가 있으면
                    map[shark.first][shark.second][j] = 0;
                    smell[shark.first][shark.second] = 3;
                }
            }
        }

        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                smell[i][j] = max(0, smell[i][j] - 1);
            }
        }

        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                for (int k = 1; k <= 8; k++) {
                    map[i][j][k] += duplica[i][j][k];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 8; k++) {
                ans += map[i][j][k];
            }
        }
    }
    cout << ans;
}