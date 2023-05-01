#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n, m, map[20][20];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;

struct group {
    int cnt;
    int rainbowCnt;
    int stdRow;
    int stdCol;
    vector<pair<int, int>> element;
};

vector<group> v;

bool compare(group& g1, group& g2) {
    if (g1.cnt == g2.cnt) {
        if (g1.rainbowCnt == g2.rainbowCnt) {
            if (g1.stdRow == g2.stdRow) {
                return g1.stdCol > g2.stdCol;
            }
            return g1.stdRow > g2.stdRow;
        }
        return g1.rainbowCnt > g2.rainbowCnt;
    }
    return g1.cnt > g2.cnt;
}

void getGroup() {
    int visit[20][20] = {
        0,
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            queue<pair<int, int>> rainbowQ;
            if (!visit[i][j] && map[i][j] != -2 && map[i][j] != -1 && map[i][j] != 0) {
                group temp;
                queue<pair<int, int>> q;
                visit[i][j] = 1;
                q.push({i, j});
                temp.element.push_back({i, j});
                if (map[i][j] == 0) {
                    rainbowQ.push({i, j});
                }
                int cnt = 1, rCnt = map[i][j] == 0 ? 1 : 0;
                int stdr = i, stdc = j;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && (map[nx][ny] == map[i][j] || map[nx][ny] == 0)) {
                            q.push({nx, ny});
                            visit[nx][ny] = 1;
                            cnt++;
                            if (map[nx][ny] == 0) {
                                rCnt++;
                                rainbowQ.push({nx, ny});
                            }
                            temp.element.push_back({nx, ny});
                            if (map[nx][ny] != 0 && (nx < stdr || (nx == stdr && ny < stdc))) {
                                stdr = nx;
                                stdc = ny;
                            }
                        }
                    }
                }

                while (!rainbowQ.empty()) {
                    visit[rainbowQ.front().first][rainbowQ.front().second] = 0;
                    rainbowQ.pop();
                }

                temp.cnt = cnt;
                temp.rainbowCnt = rCnt;
                temp.stdRow = stdr;
                temp.stdCol = stdc;
                if (temp.element.size() >= 2) {
                    v.push_back(temp);
                }
            }
        }
    }
}

void gravity() {
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (map[i][j] == -2 || map[i][j] == -1) continue;

            int idx = i + 1;
            while (idx < n && map[idx][j] == -2) {
                idx++;
            }

            if (idx == n && i != n - 1) {
                map[n - 1][j] = map[i][j];
                map[i][j] = -2;
            } else {
                if (i != idx - 1) {
                    map[idx - 1][j] = map[i][j];
                    map[i][j] = -2;
                }
            }
        }
    }
}

void rotate() {
    int newMap[20][20] = {
        0,
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newMap[i][j] = map[j][n - i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = newMap[i][j];
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    while (1) {
        v.clear();
        getGroup();
        if (v.empty()) {
            break;
        }
        sort(v.begin(), v.end(), compare);
        ans += v[0].element.size() * v[0].element.size();
        for (int i = 0; i < v[0].element.size(); i++) {
            map[v[0].element[i].first][v[0].element[i].second] = -2;
        }
        gravity();
        rotate();
        gravity();
    }

    cout << ans;
}