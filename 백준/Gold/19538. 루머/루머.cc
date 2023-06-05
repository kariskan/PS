#include <iostream>
#include <queue>
using namespace std;

int n;
vector<vector<int>> v;
queue<int> q;
int vis[200001], cnt[200001], ans[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        ans[i] = -1;
        while (1) {
            int a;
            cin >> a;
            if (a == 0) {
                break;
            }
            v[i].push_back(a);
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        vis[a] = 1;
        q.push(a);
        ans[a] = 0;
    }

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (auto &i : v[a]) {
            if (!vis[i]) {
                cnt[i]++;
                if (cnt[i] >= (v[i].size() + 1) / 2) {
                    ans[i] = vis[a];
                    q.push(i);
                    vis[i] = vis[a] + 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}