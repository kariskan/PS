#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<vector<int>> v(100001);
vector<int> parent(100001);
vector<int> o;
queue<int> q;
int visit[100001];
int idx = 0;
int bfs() {
    int m = 1;
    while (!q.empty() && idx <= n) {
        int a = q.front();
        q.pop();
        if (a != o[idx])return 0;
        int cnt = 0;
        int vSize = v[a].size();
        for (int i = 0; i < vSize; i++) {
            if (!visit[v[a][i]]) {
                parent[v[a][i]] = a;
                cnt++;
            }
        }
        int qSize = q.size();
        for (int i = 0; i < cnt; i++) {
            if (m + i > n || parent[o[m + i]] != a) {
                return 0;
            }
            q.push(o[m + i]);
            visit[o[m + i]] = 1;
        }
        m += cnt;
        idx++;
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        o.push_back(a);
    }
    q.push(1);
    visit[1] = 1;
    cout << bfs();
}