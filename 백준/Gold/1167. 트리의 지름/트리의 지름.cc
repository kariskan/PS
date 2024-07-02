#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// 50 30 24 05 28 45 98 52 60
// 05 28 24 45 30 60 52 98 50

int n, maxNode, maxWeight;
vector<vector<pair<int, int> > > v;

int go(int node, int pre, int w) {
    for (auto &i: v[node]) {
        if (i.first == pre) {
            continue;
        }
        int res = go(i.first, node, w + i.second);
        if (maxWeight < res) {
            maxWeight = res;
            maxNode = i.first;
        }
    }
    return w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int vertex;
        cin >> vertex;
        while (1) {
            int a;
            cin >> a;
            if (a == -1) {
                break;
            }
            int b;
            cin >> b;
            v[vertex].push_back({a, b});
        }
    }
    go(1, 0, 0);
    go(maxNode, 0, 0);
    cout << maxWeight;
}
