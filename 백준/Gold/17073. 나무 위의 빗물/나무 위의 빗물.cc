#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int n, w, leaf;
vector<vector<int> > v;

void go(int node, int pre) {
    bool isLeaf = true;
    for (auto &i: v[node]) {
        if (i != pre) {
            go(i, node);
            isLeaf = false;
        }
    }
    if (isLeaf) {
        leaf++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    go(1, 0);

    cout.precision(6);

    cout << fixed << (double) w / leaf;
}
