#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int visit[100][100];
string s[101];
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;
int run() {
    
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x[k] + i;
            int ny = y[k] + j;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] == '1' && !visit[nx][ny]) {
                if (!visit[nx][ny])visit[nx][ny] = visit[i][j] + 1;
                q.push({ nx,ny });
            }
        }
    }
    return visit[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    q.push({ 0,0 });
    visit[0][0] = 1;
    cout << run();
}