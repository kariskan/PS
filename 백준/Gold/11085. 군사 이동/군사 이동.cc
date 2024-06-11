#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int p, w, c, v;
vector<pair<pair<int, int>, int>> inp;
vector<vector<pair<int, int>>> ve;
vector<int> dis;
int parent[1000];

int Find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    parent[a] = b;
}

int ans = 987654321;

void dfs(int node, int pre) {
    for (auto& i : ve[node]) {
        if (i.first != pre) {
            dis[i.first] = min(dis[node], i.second);
            dfs(i.first, node);
        }
    }
}

int main() {
    cin >> p >> w >> c >> v;

    ve.resize(p);
    dis.resize(p, 987654321);

    for (int i = 0; i < p; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < w; i++) {
        int a, b, ed;
        cin >> a >> b >> ed;
        inp.push_back({ {a, b}, ed });
    }

    sort(inp.begin(), inp.end(), [](pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2) -> bool { return p1.second > p2.second; });

    for (int i = 0; i < inp.size(); i++) {
        int a = inp[i].first.first;
        int b = inp[i].first.second;
        if (Find(a) != Find(b)) {
            Union(a, b);
            ve[a].push_back({ b, inp[i].second });
            ve[b].push_back({ a, inp[i].second });
        }
    }

    dfs(c, -1);

    cout << dis[v];
}