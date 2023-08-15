#include <iostream>
#include <map>
#include <set>
using namespace std;

int p[1000000];
int n, m, vis[1001][1001];
char board[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
map<char, int> ma = {{'N', 3}, {'S', 2}, {'W', 1}, {'E', 0}};

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

bool range(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= n * m; i++) {
        p[i] = i;
    }
    int parent = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                int x = i, y = j;
                while (!vis[x][y] && range(x, y)) {
                    vis[x][y] = parent;
                    int nx = x + dx[ma[board[x][y]]];
                    int ny = y + dy[ma[board[x][y]]];
                    x = nx, y = ny;
                }
                if (range(x, y)) {
                    Union(vis[i][j], vis[x][y]);
                }
                parent++;
            }
        }
    }
    set<int> se;
    for (int i = 1; i < parent; i++) {
        se.insert(Find(i));
    }
    cout << se.size();
}