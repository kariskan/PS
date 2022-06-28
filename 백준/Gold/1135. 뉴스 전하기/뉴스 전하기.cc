#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> tree;

int dfs(int root) {

    int ret = 0;
    vector<int> v;

    for (int i = 0; i < tree[root].size(); i++) {
        v.push_back(dfs(tree[root][i]));
    }

    sort(v.begin(), v.end());
    int subSize = v.size();

    for (int i = 0; i < v.size(); i++) {
        ret = max(ret, v[i] + subSize - i);
    }
    return ret;
}

int main() {
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (!i)continue;
        tree[a].push_back(i);
    }
    cout << dfs(0);
}