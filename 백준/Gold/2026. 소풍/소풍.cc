#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int vis[901], map[901][901];
int k, n, f;

bool check(vector<int> seq, int idx) {
    for (int i = 0; i < seq.size(); i++) {
        if (!map[seq[i]][idx]) {
            return false;
        }
    }
    return true;
}

void go(int node, vector<int> seq) {
    vis[node] = 1;
    if (seq.size() == k) {
        for (int i = 0; i < seq.size(); i++) {
            cout << seq[i] << '\n';
        }
        exit(0);
    }

    for (auto& i : v[node]) {
        if (!vis[i] && check(seq, i) && seq.size() + v[i].size() + 1 >= k) {
            seq.push_back(i);
            go(i, seq);
            seq.pop_back();
        }
    }
    vis[node] = 0;
}

int main() {
    cin >> k >> n >> f;
    v.resize(n + 1);

    for (int i = 0; i < f; i++) {
        int a, b;
        cin >> a >> b;
        v[min(a, b)].push_back(max(a, b));
        map[a][b] = map[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }

    for (int i = 1; i <= n; i++) {
        go(i, {i});
    }

    cout << -1;
}