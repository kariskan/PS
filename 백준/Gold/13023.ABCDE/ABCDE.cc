#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<vector<int>> v;
int visit[2000];
int b = 0;
void run(int cnt, int index) {
    if (cnt >= 5) {
        b = 1;
        return;
    }

    int vSize = v[index].size();
    for (int i = 0; i < vSize; i++) {
        if (!visit[v[index][i]] && v[index][i] != index) {
            visit[v[index][i]] = 1;
            run(cnt + 1, v[index][i]);
            if (b)return;
            visit[v[index][i]] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        visit[i] = 1;
        run(1, i);
        visit[i] = 0;
    }
    cout << b ? 1 : 0;
}