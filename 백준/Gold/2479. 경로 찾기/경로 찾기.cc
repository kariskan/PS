#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int n, m, s, e, vis[1001];
string inp[1001];

// 해밍 거리를 구하는 함수
int getDis(string s1, string s2) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        res += (s1[i] != s2[i] ? 1 : 0);
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> inp[i];
    }
    cin >> s >> e;
    vector<vector<pair<int, int>>> v(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) { // 모든 정점을 탐색해서

            int d = getDis(inp[i], inp[j]);

            // 해밍 거리가 1일때만 인접 리스트에 추가
            if (d == 1) {
                v[i].push_back({j, d});
                v[j].push_back({i, d});
            }
        }
    }

    queue<pair<int, string>> q;
    q.push({s, to_string(s)});
    vis[s] = 1;

    // bfs
    while (!q.empty()) {
        int node = q.front().first;
        string path = q.front().second;
        q.pop();

        if (node == e) {
            cout << path;
            return 0;
        }

        for (auto &i : v[node]) {
            if (!vis[i.first]) {
                vis[i.first] = vis[node] + 1;
                q.push({i.first, path + " " + to_string(i.first)});
            }
        }
    }

    cout << -1;
}