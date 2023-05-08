#include <iostream>
#include <queue>
using namespace std;

char map[10][10];
int vis[10][10][10][10];
pair<int, int> red, blue;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'R') {
                red = {i, j};
                map[i][j] = '.';
            }
            if (map[i][j] == 'B') {
                blue = {i, j};
                map[i][j] = '.';
            }
        }
    }

    queue<pair<pair<int, int>, pair<int, int>>> q;

    q.push({red, blue});
    vis[red.first][red.second][blue.first][blue.second] = 1;

    for (int i = 1;; i++) {
        int siz = q.size();
        for (int j = 0; j < siz; j++) {
            pair<int, int> nowRed = q.front().first;
            pair<int, int> nowBlue = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                pair<int, int> next[2] = {nowRed, nowBlue};
                int end[2] = {
                    0,
                };
                int idx = 1;

                if ((k == 0 && nowRed.first < nowBlue.first) || (k == 1 && nowRed.first > nowBlue.first) || (k == 2 && nowRed.second < nowBlue.second) || (k == 3 && nowRed.second > nowBlue.second)) {
                    idx = 0;
                }

                for (int l = 0; l < 2; l++) {
                    while (1) {
                        if (map[next[idx].first][next[idx].second] != '.') {
                            break;
                        }

                        next[idx].first += dx[k];
                        next[idx].second += dy[k];
                    }

                    if (map[next[idx].first][next[idx].second] == 'O') {
                        end[idx] = 1;
                    } else {
                        next[idx].first -= dx[k];
                        next[idx].second -= dy[k];
                        map[next[idx].first][next[idx].second] = 'X';
                    }

                    idx = 1 - idx;
                }

                if (end[0] && !end[1]) {
                    cout << i;
                    return 0;
                }

                for (int l = 0; l < 2; l++) {
                    if (!end[l]) map[next[l].first][next[l].second] = '.';
                }

                if (!end[1]) {
                    if (!vis[next[0].first][next[0].second][next[1].first][next[1].second]) {
                        q.push({next[0], next[1]});
                        vis[next[0].first][next[0].second][next[1].first][next[1].second] = 1;
                    }
                }
            }
        }

        if (i > 300) {
            break;
        }
    }

    cout << -1;
}