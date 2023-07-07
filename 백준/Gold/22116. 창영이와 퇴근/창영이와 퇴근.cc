#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, a[1001][1001];
vector<vector<pair<int, int>>> v;
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

int main() {
    cin >> n;
    v.resize(n * n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + x[k];
                int ny = j + y[k];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                    v[(i - 1) * n + j].push_back(
                        {(nx - 1) * n + ny, abs(a[i][j] - a[nx][ny])});
                }
            }
        }
    }

    priority_queue<pair<int, int>> q;
    vector<int> dis(n * n + 1, 2000000000);

    dis[1] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        int node = q.top().second;
        int cost = -q.top().first;
        q.pop();

        if (dis[node] < cost) {
            continue;
        }

        for (auto &i : v[node]) {
            int nxNode = i.first;
            int nxCost = max(cost, i.second);
            if (dis[nxNode] > nxCost) {
                dis[nxNode] = nxCost;
                q.push({-nxCost, nxNode});
            }
        }
    }
    
    cout << dis[n * n]; 
}