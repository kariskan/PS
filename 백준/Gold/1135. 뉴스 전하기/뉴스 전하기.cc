#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int n;
vector<vector<int>> v;

int go(int node) {
    if (v[node].empty()) {
        return 0;
    }
    vector<int> child;
    for (int i = 0; i < v[node].size(); i++) {
        child.push_back(go(v[node][i]));
    }
    sort(child.begin(), child.end());
    int res = 0;
    for (int i = 0; i < child.size(); i++) {
        res = max(res, child[i] + (int) child.size() - i);
    }
    return res;
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i == 0) {
            continue;
        }
        v[a].push_back(i);
    }

    cout << go(0);
}