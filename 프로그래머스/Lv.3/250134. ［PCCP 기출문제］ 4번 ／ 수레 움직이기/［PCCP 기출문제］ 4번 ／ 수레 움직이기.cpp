#include <string>
#include <vector>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int map[4][4], vis[2][4][4], n, m;
int answer = 1000000000;

bool range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && map[x][y] != 5;
}

// arrive -> 도착한 공의 개수
// cnt -> 이동 횟수
void go(int arrive, int cnt, int rx, int ry, int bx, int by) {
    if (arrive == 2) {
        answer = min(answer, cnt);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int rnx = map[rx][ry] == 3 ? rx : rx + dx[i];
        int rny = map[rx][ry] == 3 ? ry : ry + dy[i];
        for (int j = 0; j < 4; j++) {
            int bnx = map[bx][by] == 4 ? bx : bx + dx[j];
            int bny = map[bx][by] == 4 ? by : by + dy[j];
            int postArrive = arrive;
            int postVis1 = vis[0][rnx][rny];
            int postVis2 = vis[1][bnx][bny];

            if (rnx == bnx && rny == bny) {
                continue;
            }
            if (!range(rnx, rny) || !range(bnx, bny)) {
                continue;
            }
            if ((vis[0][rnx][rny] && map[rnx][rny] != 3)
                || (vis[1][bnx][bny] && map[bnx][bny] != 4)) {
                continue;
            }
            if (bx == rnx && by == rny && rx == bnx && ry == bny) {
                continue;
            }
            vis[0][rnx][rny] = 1;
            vis[1][bnx][bny] = 1;
            if (map[rx][ry] != 3 && map[rnx][rny] == 3) {
                arrive++;
            }
            if (map[bx][by] != 4 && map[bnx][bny] == 4) {
                arrive++;
            }
            go(arrive, cnt + 1, rnx, rny, bnx, bny);
            arrive = postArrive;
            vis[0][rnx][rny] = postVis1;
            vis[1][bnx][bny] = postVis2;
        }
    }
}

int solution(vector<vector<int>> maze) {
    n = maze.size();
    m = maze[0].size();
    int rx, ry, bx, by;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = maze[i][j];
            if (map[i][j] == 1) {
                rx = i;
                ry = j;
            }
            if (map[i][j] == 2) {
                bx = i;
                by = j;
            }
        }
    }
    vis[0][rx][ry] = 1;
    vis[1][bx][by] = 1;
    go(0, 0, rx, ry, bx, by);
    return answer == 1000000000 ? 0 : answer;
}