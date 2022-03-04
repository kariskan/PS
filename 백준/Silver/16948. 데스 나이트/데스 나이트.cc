#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[200][200] = { 0, };
    int visit[200][200] = { 0, };
    int x[6] = { -2,-2,0,0,2,2 };
    int y[6] = { -1,1,-2,2,-1,1 };
    int a2, b2, a1, b1;
    queue<pair<int, int>> q;
    cin >> a2 >> b2;
    q.push({ a2,b2 });
    cin >> a1 >> b1;
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        if (i == a1 && j == b1)break;
        q.pop();
        for (int k = 0; k < 6; k++) {
            int nx = i + x[k];
            int ny = j + y[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny]) {
                q.push({ nx,ny });
                visit[nx][ny] = visit[i][j] + 1;
            }
        }
    }
    if (visit[a1][b1] == 0 && (a1 != a2 || b1 != b2))cout << -1;
    else cout << visit[a1][b1];
}