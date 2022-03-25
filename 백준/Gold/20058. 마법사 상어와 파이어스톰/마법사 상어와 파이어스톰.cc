#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<vector<int>> rotate(vector<vector<int>> a) {
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = a[n - j - 1][i];
        }
    }
    return ans;
}
void firestorm(vector<vector<int>>& a, int sx, int sy, int size) {
    vector<vector<int>> b(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            b[i][j] = a[sx + i][sy + j];
        }
    }
    b = rotate(b);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a[sx + i][sy + j] = b[i][j];
        }
    }

}
int main() {
    int n, q;
    cin >> n >> q;
    int m = (1 << n);
    vector<vector<int>> a(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (q--) {
        int l;
        cin >> l;
        if (l > 0) {
            int size = (1 << l);
            for (int sx = 0; sx < m; sx += size) {
                for (int sy = 0; sy < m; sy += size) {
                    firestorm(a, sx, sy, size);
                }
            }
        }
        vector<vector<int>> b(a);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) continue;
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < m && 0 <= ny && ny < m) {
                        if (b[nx][ny] > 0) {
                            cnt += 1;
                        }
                    }
                }
                if (cnt >= 3) {
                }
                else {
                    if (a[i][j] > 0) {
                        a[i][j] -= 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            ans += a[i][j];
        }
    }
    cout << ans << endl;
    vector<vector<bool>> check(m, vector<bool>(m));
    ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            if (check[i][j] == true) continue;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            int cnt = 1;
            check[i][j] = true;
            while (!q.empty()) {
                int x, y;
                tie(x, y) = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (0 <= nx && nx < m && 0 <= ny && ny < m) {
                        if (a[nx][ny] != 0 && check[nx][ny] == false) {
                            check[nx][ny] = true;
                            q.push(make_pair(nx, ny));
                            cnt += 1;
                        }
                    }
                }
            }
            if (ans < cnt) ans = cnt;
        }
    }
    cout << ans << endl;
    return 0;
}