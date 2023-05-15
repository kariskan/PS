#include <iostream>
#include <vector>
using namespace std;

int n, m, k, jewel[101], ans;
vector<vector<pair<int, int>>> v;
int vis[101][(1 << 15) + 1];

// 현재 노드, 현재 방문 상태, 현재 가지고 있는 보석 수
void go(int node, int state, int cnt) {
    if (node == 1) {
        ans = max(ans, cnt);
    }

    vis[node][state] = 1;

    for (auto& i : v[node]) {
        if (i.second < cnt) continue;

        // 보석 선택하지 않는 경우
        if (!vis[i.first][state]) {
            go(i.first, state, cnt);
        }

        // 보석 선택하는 경우
        if (jewel[i.first]) {
            if (i.second < cnt + 1) continue;

            if (!vis[i.first][state | (1 << jewel[i.first])]) {
                go(i.first, state | (1 << jewel[i.first]), cnt + 1);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    v.resize(n + 1);

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        jewel[a] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    v[1].push_back({1, 100});

    go(1, 0, 0);
    
    cout << ans;
}