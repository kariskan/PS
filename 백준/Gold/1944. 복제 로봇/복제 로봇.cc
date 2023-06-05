#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, m, p[251], seq[51][51];
char map[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<pair<int, int>, int>> v;

bool compare(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2) {
    return p1.second < p2.second;
}

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    p[a] = b;
}

int main() {
    cin >> n >> m;
    int idx = 0;
    for (int i = 1; i <= m; i++) {
        p[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S' || map[i][j] == 'K') {
                seq[i][j] = idx++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'S' || map[i][j] == 'K') {
                queue<pair<int, int>> q;
                int vis[51][51] = {0};
                int temp = 0;
                q.push({i, j});
                vis[i][j] = 1;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                            !vis[nx][ny] && map[nx][ny] != '1') {
                            if (map[nx][ny] == 'S' || map[nx][ny] == 'K') {
                                v.push_back(
                                    {{seq[i][j], seq[nx][ny]}, vis[x][y]});
                                temp++;
                            }
                            vis[nx][ny] = vis[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
                if (temp != m) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    int ans = 0;
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++) {
        if (Find(v[i].first.first) != Find(v[i].first.second)) {
            Union(v[i].first.first, v[i].first.second);
            ans += v[i].second;
        }
    }
    cout << ans;
}